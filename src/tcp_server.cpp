#include "tcp_server.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <iostream>
#include <fstream>
namespace ip =  boost::asio::ip;

namespace connectserver{

	raspar_tcp_server::raspar_tcp_server(int port_number,boost::asio::io_service& io_service)
	{
		m_port_number = port_number;
		m_acceptor = new ip::tcp::acceptor(io_service,ip::tcp::endpoint(ip::tcp::v4(), m_port_number));
		m_socket = new ip::tcp::socket(io_service);
		m_is_connect = false;
	}

	void raspar_tcp_server::accept(){
		std::cout << "[TCP] Start Accept" << std::endl;
		m_acceptor->async_accept(*m_socket,
				boost::bind(&raspar_tcp_server::on_accept,this,boost::asio::placeholders::error));
	}

	void raspar_tcp_server::on_accept(const boost::system::error_code& error){
		if (error) {
			std::cout << "accept failed: " << error.message() << std::endl;
			return;
		}
		std::cout << "[TCP] Server Start" << std::endl;
		receive();
	}

	void raspar_tcp_server::receive(){
			boost::asio::async_read_until(
					*m_socket,m_receive_buff,'\n',
					boost::bind(&raspar_tcp_server::on_receive,this,
						boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
	}


	void raspar_tcp_server::on_receive(const boost::system::error_code& error,size_t bytes_transferred){
		std::cout <<  "[TCP] message comming " << std::endl;
		if (error && error != boost::asio::error::eof) {
			std::cout << "receive failed: " << error.message() << std::endl;
		}
		else {
			const char* data = boost::asio::buffer_cast<const char*>(m_receive_buff.data());
			std::cout << "[TCP] Data:" <<  data << std::endl;
			m_receive_buff.consume(m_receive_buff.size());
		}
	}
}

