require 'socket'

port = 8080
server = TCPServer.new('127.0.0.1',port)

puts "start tcp server"

while true 
	socket = server.accept

	while line = socket.gets
		puts line
	end
	socket.close
end
