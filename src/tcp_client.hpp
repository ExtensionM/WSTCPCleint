#ifndef WSCLIENT_TCP_CLIENT_HPP
#define WSCLIENT_TCP_CLIENT_HPP

#include <boost/asio.hpp>

#include <iostream>

namespace ip =  boost::asio::ip;

namespace connectserver{

	class tcp_client {
		public:
			tcp_client(int port_number);
			void connect();
			void send(std::string message);
		protected:
			void on_send(const boost::system::error_code& error,size_t bytes_transferred);
		private:
			boost::asio::io_service m_io_service;
			ip::tcp::socket * m_socket;

			int m_port_number;
			bool m_is_connect;


	};

}

#endif 
