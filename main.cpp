#include "src/server_ras_client.hpp"
#include "src/tcp_server.hpp"

#include <boost/bind.hpp>

using namespace connectserver;

int main(){
	server_ras_client *s_client = new server_ras_client("ws://ec2-52-68-77-61.ap-northeast-1.compute.amazonaws.com:3000");
	s_client->connect();
	s_client->start();
}
