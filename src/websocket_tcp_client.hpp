#ifndef SERVER_RAS_CLIENT_HPP
#define SERVER_RAS_CLIENT_HPP

#include <websocketpp/config/asio_client.hpp>

#include <websocketpp/client.hpp>

#include <string>

#include "tcp_client.hpp"

typedef websocketpp::client<websocketpp::config::asio_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;


namespace connectserver {

	class server_ras_client {
		typedef server_ras_client type;

		public:
			server_ras_client(std::string uri);
			void connect();
			void start();
			void send(std::string meesage);

			const std::string get_status();
			const std::string get_message();

		protected:
			void on_open(websocketpp::connection_hdl hdl);
			void on_message(websocketpp::connection_hdl hdl,message_ptr msg);
			void on_close(websocketpp::connection_hdl hdl);

		private:
			client m_client;
			websocketpp::connection_hdl m_hdl;
			tcp_client *  m_tcp_client;

			std::string m_status;
			std::string m_url;
			std::string m_msg;

			bool m_is_connect;

			std::string generate_json();
	};

} //namespace connectserver

#endif
