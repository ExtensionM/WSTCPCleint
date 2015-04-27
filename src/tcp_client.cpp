#include "tcp_client.hpp"

#include <boost/asio.hpp>

#include <iostream>

typedef boost::asio::ip::tcp::socket sockect;

namespace connectserver{

	tcp_client::tcp_client(int port_number){
	
	}
	
	tcp_client::connect(){
	
	}
	
	tcp_client::send(std::string message){

	}
	
	tcp_client::on_connect(const boost::system::error_code & error){

	}

	tcp_client::on_send(const boost::system::error_code & error,size_t bytes_readable){

	}
}

