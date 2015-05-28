#include "tcp_server.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include <iostream>

namespace ip =  boost::asio::ip;

namespace connectserver{

	raspar_tcp_client::raspar_tcp_client(int port_number,boost::asio::io_service& io_service)
	{
		m_port_number = port_number;
		m_acceptor = new ip::tcp::acceptor(io_service,ip::tcp::endpoint(ip::tcp::v4(), m_port_number));
		m_socket = new ip::tcp::socket(io_service);
		m_is_connect = false;
	}

	void raspar_tcp_client::accept(){
		m_acceptor->async_accept(*m_socket,
				boost::bind(&raspar_tcp_client::on_accept,this,boost::asio::placeholders::error));
	}

	void raspar_tcp_client::on_accept(const boost::system::error_code& error){
		if (error) {
			std::cout << "accept failed: " << error.message() << std::endl;
			return;
		}
		receive();
	}

	void raspar_tcp_client::receive(){
		boost::asio::async_read(
				*m_socket,m_receive_buff,boost::asio::transfer_all(),
				boost::bind(&raspar_tcp_client::on_receive,this,
					boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
	}


	void raspar_tcp_client::on_receive(const boost::system::error_code& error,size_t bytes_transferred){
		if (error && error != boost::asio::error::eof) {
			std::cout << "receive failed: " << error.message() << std::endl;
		}
		else {
			const char* data = boost::asio::buffer_cast<const char*>(m_receive_buff.data());
			std::cout << data << std::endl;

			m_receive_buff.consume(m_receive_buff.size());
		}
	}
}

