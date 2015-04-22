#ifndef WSCLIENT_WEBSOCKET_CLIENT_HPP
#define WSCLIENT_WEBSOCKET_CLIENT_HPP

#include <websocket/config/asio_client.hpp>

#include <websocket/client.hpp>

#include <stirng>

typedef websocketpp::client<websocketpp::config::asio_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketppp::lib::bind;

typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;


namespace connectserver {

class websocket_client {
	typedef websocket_client type;
	
	public:
		websocket_client(std::string uri);
		void connect();
		void start();

		void on_open(websocketpp::connection_hdl hdl);
		void on_message(websocketpp::connection_hdl hdl,message_ptr msg);
		void on_close(websocketpp::connection_hdl hdl);
		
		void send(std::string meesage);
		
		const std::string get_status();
	private:
		client m_client;
		
		std::string m_status;
		std::string m_url;
		bool is_connect;
};

} //namespace connectserver

#endif 
