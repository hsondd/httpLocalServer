# HTTP SERVER

## Build from source

```
    ./build.sh
```
## Run program
```
    ./httpserver
```
## Method
### Connect mosquitto broker
```
    GET http://localhost:8000/connect
```
### Subscribe topic/pub and topic/sub
```
    GET http://localhost:8000/connect/sub
```
### Subscribe topic/sub Publish message "hi from local" to topic/sub
```
    GET http://localhost:8000/connect/pub
```
