#include <iostream>
#include <assert.h>

#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>

#include <string>
#include <tuple>
#include <cstdint>
#include <signal.h>

#include <unistd.h>
#include <mosquittopp.h>
#include <string>

#define UNUSED(expr) do { (void)(expr); } while (0)

class myMosquitto : public mosqpp::mosquittopp
{
public:
    myMosquitto(const char* id, const char* _host, int port_);
    ~myMosquitto();

    void subscribe_to_topic(std::string topic){
      int ret = subscribe(NULL, topic.c_str());
      if (ret != MOSQ_ERR_SUCCESS){
          std::cout << "Subcribe failed" << std::endl;
      }
      else std::cout << "Subcribe success " << topic << std::endl;
    }
    void unsubscribe_from_topic(std::string topic);
    void myPublish(std::string topic, std::string mess);
private:
    void on_connect(int rc){
      if ( rc == 0 ) {
        std::cout << "Connected success with server: "<< this->host << std::endl;
        // std::cout << "Enter message: ";
        // std::getline(std::cin,mess);
      } 
      else{
        std::cout << "Cant connect with server(" << rc << ")" << std::endl;
      }
    }

    void on_disconnect(int rc){
      std::cout << "Disconnected (" << rc << ")" << std::endl;
    }
    void on_message(const struct mosquitto_message *message){
      std::string payload = std::string(static_cast<char *>(message->payload));
      std::string topic = std::string(message->topic);

      std::cout << "payload: " << payload << std::endl;
      std::cout << "topic: " << topic << std::endl;
      std::cout << "On message( QoS: " << message->mid 
                      << " - Topic: " << std::string(message->topic) << " - Message: "
                      << std::string((char *)message->payload, message->payloadlen) << ")" << std::endl;
    }

    const char* host;
    const char* id;
    const char* topic;
    int portMQTT;
    int keepalive;
    std::string mess;
};

myMosquitto::myMosquitto(const char* _id, const char* _host, int _port) :
    mosquittopp(_id)
{
    int ret;
    mosqpp::lib_init();

    this->keepalive = 60;

    this->id = _id;
    this->portMQTT = _port;
    this->host = _host;
    connect_async(host,portMQTT, keepalive);

    loop_start();
}
void myMosquitto::myPublish(std::string topic, std::string mess){
    int ret = publish(NULL, topic.c_str(), mess.size(), mess.c_str(), 1, false);
    if (ret != MOSQ_ERR_SUCCESS){
        std::cout << "Send failed." << std::endl;
    }
    else std::cout << "Send success " << std::endl;
    // << mess << " >>> published to: " << topic << std::endl;
}
 

myMosquitto::~myMosquitto()
{
  loop_stop();
  mosqpp::lib_cleanup();
}


const char *id;
std::string _topic1 = "topic/sub";
std::string _topic2 = "topic/pub";
const char *host = "test.mosquitto.org";
int portMQTT = 1883;
std::string mess;

myMosquitto* mqtt;

enum class URI_TO_PATH_STATUS : std::int8_t {
  SUCCESS = 0,
  FAILURE_URI_PARSE,
  FAILURE_URI_TO_PATH,
  FAILURE_PATH_DECODE,
};

std::tuple<std::string, URI_TO_PATH_STATUS> uri_to_path(const char *uri) {
  assert(uri != NULL);

  struct evhttp_uri *decodedUri = NULL;
  const char *path = NULL;
  const char *decodedPath = NULL;

  URI_TO_PATH_STATUS status = URI_TO_PATH_STATUS::SUCCESS;

  decodedUri = evhttp_uri_parse(uri);

  if (!decodedUri) {
    status = URI_TO_PATH_STATUS::FAILURE_URI_PARSE;
    goto end;
  }

  path = evhttp_uri_get_path(decodedUri);

  if (!path) {
    status = URI_TO_PATH_STATUS::FAILURE_URI_TO_PATH;
    goto end;
  }

  decodedPath = evhttp_uridecode(path, 0, NULL);
  if (!decodedPath) {
    status = URI_TO_PATH_STATUS::FAILURE_PATH_DECODE;
    goto end;
  }

end:
  if (decodedUri) {
    evhttp_uri_free(decodedUri);
  }

  auto result = std::make_tuple((status == URI_TO_PATH_STATUS::SUCCESS ? std::string(decodedPath) : std::string("")),status);

  free((void *)decodedPath);

  return result;
}

static void handle_file(struct evhttp_request *req, void *arg)
{
  UNUSED(arg);

  const char *uri = evhttp_request_get_uri(req);

  if (evhttp_request_get_command(req) != EVHTTP_REQ_GET) {
    evhttp_send_error(req, HTTP_BADREQUEST, 0);
    return;
  }

  std::cout << "GET " << uri << std::endl;

  auto result = uri_to_path(uri);
  auto path = std::get<0>(result);
  auto status = std::get<1>(result);

  assert(status == URI_TO_PATH_STATUS::SUCCESS);

  std::cout << "Get path " << path << std::endl;
  if(path == "/connect"){
    mqtt = new myMosquitto(id, host, portMQTT);

  }
  else if(path == "/connect/sub"){
    mqtt->subscribe_to_topic(_topic1);
    mqtt->subscribe_to_topic(_topic2);
  }
  else if(path == "/connect/pub"){
    mqtt->subscribe_to_topic(_topic2);
    mqtt->myPublish(_topic1, "hi from local");
  }

  evhttp_send_error(req, HTTP_OK, 0);

}

void signalHandle(int signum){
  std::cout << " Catch signal " << signum << std::endl << "Exit program" << std::endl;
  exit(signum);
}

int main(int argc, char **argv)
{
  signal(SIGINT, signalHandle);
  UNUSED(argc);
  struct event_base *base;
  struct evhttp *http;
  struct evhttp_bound_socket *handle;

  const ev_uint16_t port = 8000;
  const char *host = "0.0.0.0";

  base = event_base_new();

  if (!base) {
    std::cerr << "FAILURE: Couldn't create an event_base." << std::endl;
    return 1;
  }

  http = evhttp_new(base);

  if (!http) {
    std::cerr << "FAILURE: Couldn't create an evhttp." << std::endl;
    return 1;  
  }

  evhttp_set_gencb(http, handle_file, argv[1]);

  handle = evhttp_bind_socket_with_handle(http, host, port);

  if (!handle) {
    std::cerr << "FAILURE: Couldn't bind to " << host << ":" << port << std::endl;
    return 1;    
  }

  event_base_dispatch(base);
  return 0;
}
