#include "websocket_client.hpp"

#include <websocket/config/asio_client.hpp>

#include <websocket/client.hpp>

#include <stirng>

websocket_client::websocket_client(std::string uri){

}

void websocket_client::connect(){
}

void websocket_client::start(){
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
}


