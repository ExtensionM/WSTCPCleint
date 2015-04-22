#include "websocket_client.hpp"

#include <websocketpp/config/asio_client.hpp>

#include <websocketpp/client.hpp>

#include <string>
#include <iostream>

typedef websocketpp::client<websocketpp::config::asio_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;

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
		m_client.set_message_handler(bind(&type::on_message,this,::_1,::_2));
		m_client.set_close_handler(bind(&type::on_close,this,::_1));
		
		//m_hdl is null in first

		//Set client status value
		m_status = "none";
		m_msg = "";
		m_is_connect = false;
	}

	void websocket_client::connect(){
		websocketpp::lib::error_code error_code;
		client::connection_ptr con = m_client.get_connection(m_url, error_code);

		if(error_code){
			m_client.get_alog().write(websocketpp::log::alevel::app,error_code.message());
		}
		//Save connection hdl from connection_ptr
		m_hdl = con->get_handle();

		m_client.connect(con);
		m_status = "connect";
		m_is_connect = true;
	}

	void websocket_client::start(){
		if(!m_is_connect){
			connect();
		}
		m_client.run();
	}

	void websocket_client::on_open(websocketpp::connection_hdl hdl){
		m_status = "open";
	}

	void websocket_client::on_message(websocketpp::connection_hdl hdl,message_ptr msg){
		m_msg = msg->get_payload();
		std::cout << m_msg << std::endl;
		send("Start");
	}

	void websocket_client::on_close(websocketpp::connection_hdl hdl){
		m_status = "close";
	}

	void websocket_client::send(std::string message){
		if(m_is_connect){
			try{
				m_client.send(m_hdl,message,websocketpp::frame::opcode::text);
			} catch (const websocketpp::lib::error_code & e){
				std::cout << e.message() << std::endl;
			} catch (...){
				std::cout << "nanika okiteru " << std::endl;
			}
		}
	}

	const std::string websocket_client::get_status(){
		return m_status;
	}
	const std::string websocket_client::get_message(){
		return m_msg;	
	}

}
