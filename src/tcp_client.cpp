#include "tcp_client.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <iostream>

namespace ip =  boost::asio::ip;

namespace connectserver{

	tcp_client::tcp_client(int port_number){
		m_port_number = port_number;
		m_socket = new ip::tcp::socket(m_io_service);
		m_is_connect = false;
	}
	
	void tcp_client::connect(){
		boost::system::error_code error;
		m_socket->connect(ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),m_port_number),error);
		if(error){
			std::cout << "Connect failed : " << error.message() << std::endl;
			return;
		}
		m_is_connect = true;

	}
	
	void tcp_client::send(std::string message){
		if(m_is_connect){
			boost::asio::async_write(*m_socket,boost::asio::buffer(message),
				boost::bind(&tcp_client::on_send,this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
		}
	}

	void tcp_client::on_send(const boost::system::error_code & error,size_t bytes_readable){
		if(error){
			std::cout << "send failed : " << error.message() << std::endl;
		}else{
			std::cout << "send success" << std::endl;
		}
	}
}

