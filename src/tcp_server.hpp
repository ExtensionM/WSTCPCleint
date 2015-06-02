#ifndef WSCLIENT_TCP_SERVER_HPP
#define WSCLIENT_TCP_SERVER_HPP

#include <boost/asio.hpp>

#include <iostream>

namespace ip =  boost::asio::ip;

namespace connectserver{

	class raspar_tcp_server {
		public:
			raspar_tcp_server(int port_number,boost::asio::io_service& io_service);
			void accept();
			void receive();
		protected:
			void on_accept(const boost::system::error_code& error);
			void on_receive(const boost::system::error_code& error,size_t bytes_transferred);
		private:
			ip::tcp::socket * m_socket;
			ip::tcp::acceptor * m_acceptor;
			boost::asio::streambuf m_receive_buff;

			int m_port_number;
			bool m_is_connect;
	};

}

#endif 
