#include "src/websocket_client.hpp"

#include <iostream>
#include <string>

using namespace connectserver;

int main(int argc,char **argv){
	int port = 8080;
	websocket_client *wclient = new websocket_client("ws://ec2-52-68-77-61.ap-northeast-1.compute.amazonaws.com:3000");
	wclient->connect();
	wclient->start();
	delete wclient;
}

