#include "src/server_ras_client.hpp"
#include "src/tcp_server.hpp"

#include <boost/bind.hpp>
#include <iostream>

using namespace connectserver;

int main(){
	std::string url;
	std::cout << "Please Input URL" << std::endl;
	cin >> url;
	server_ras_client *s_client = new server_ras_client(url);
	s_client->connect();
	s_client->start();
}
