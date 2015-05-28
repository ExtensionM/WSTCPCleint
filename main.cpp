#include "src/server_ras_client.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace connectserver;

int main(int argc,char **argv){
	server_ras_client *s_client = new server_ras_client("ws://ec2-52-68-77-61.ap-northeast-1.compute.amazonaws.com:3000");
	s_client->connect();
	s_client->start();
	delete s_client;
}

