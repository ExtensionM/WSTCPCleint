#include "src/tcp_client.hpp"

#include <iostream>
#include <string>

using namespace connectserver;

int main(int argc,char **argv){
	int port = 8080;
	tcp_client *tclient = new tcp_client(port);
	tclient->connect();
	tclient->send("test");
	delete tclient;
}

