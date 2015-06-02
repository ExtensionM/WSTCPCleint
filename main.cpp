#include "src/server_ras_client.hpp"
#include "src/tcp_server.hpp"

#include <boost/bind.hpp>

using namespace connectserver;

int main(){
	auto th1 = std::thread([]{
		boost::asio::io_service io_service;
		raspar_tcp_server *tcp_server = new raspar_tcp_server(10000,io_service);
		tcp_server->accept();
		io_service.run();
		std::cout << "[TCP] Server is down!" << std::endl;
	});
	th1.detach();
	server_ras_client *s_client = new server_ras_client("ws://ec2-52-68-77-61.ap-northeast-1.compute.amazonaws.com:3000");
	s_client->connect();
	s_client->start();
}
