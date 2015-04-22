#include "websocket_client.hpp"

#include <websocket/config/asio_client.hpp>

#include <websocket/client.hpp>

#include <stirng>

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketppp::lib::bind;

namespace connectserver{

	websocket_client::websocket_client(std::string uri){
		// set url
		m_url = uri;

		m_client.set_access_channels(websocketpp::log::alevel::all);
		m_client.set_error_channels(websocketpp::log::elevel::all);

		//Initialize ASIO
		m_client.init_asio();
		
		//Register our Handler
		m_client.set_open_handler(bind(&type::on_open,this,::_1));
		m_client.set_message_handler(bind(&type::on_message,this,::_1));
		m_client.set_close_handler(bind(&type::on_close,this,::_1));
	}

	void websocket_client::connect(){
		websocket_client::lib::error_code error_code;
		client::connection_ptr con = m_client.get_connection(m_url, error_code);

		if(error_code){
			m_client.get_alog().write(websocketpp::log::alevel::app,error_code.message());
		}
		m_client.connect(con);
		m_status = "connect";
	}

	void websocket_client::start(){
		if(m_status != "connect"){
			this.connect();
		}
		m_client.run();
	}

	void websocket_client::on_open(websocketpp::connection_hdl hdl){
	}

	void websocket_client::on_message(websocketpp::connection_hdl hdl){
	}

	void websocket_client::on_close(websocketpp::connection_hdl hdl){
	}

	void websocket_client::send(std::string message){
	}

	const std::string websocket_client::get_status(){
		return m_status;
	}

}
