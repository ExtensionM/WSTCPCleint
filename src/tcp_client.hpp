#ifndef WSCLIENT_TCP_CLIENT_HPP
#define WSCLIENT_TCP_CLIENT_HPP

#include <boost/asio.hpp>

#include <iostream>

typedef boost::asio::ip::tcp::socket sockect;

namespace connectserver{

class tcp_client {
	public:
		tcp_client(int port_number);
		void connect();
		void send(std::string message);
	private:
		boost::asio::io_service m_io_service;
		socket m_socket;
		
		int m_port_number;
		bool m_is_connect;

		void on_connect(const boost::system::error_code & error);
		void on_send(const boost::system::error_code& error,size_t bytes_transferred);

};

}

#endif 
