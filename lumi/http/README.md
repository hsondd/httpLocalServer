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
### Subscribe topic
```
    GET http://localhost:8000/connect/sub
```
### Publish message
```
    GET http://localhost:8000/connect/pub
```
