#include "src/websocket_client.hpp"

#include <iostream>
#include <string>

using namespace connectserver;

int main(int argc,char **argv){
	std::string url = "ws://ec2-52-68-77-61.ap-northeast-1.compute.amazonaws.com:3000";
	websocket_client *ws = new websocket_client(url);
	ws->connect();
	ws->start();
	delete ws;
}

