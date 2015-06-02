require 'socket' 

puts "Please Input Port Number:"
port = gets.chomp
client = TCPSocket.new('localhost',port)
client.write("{\"guid\":\"Test\",\"guid\":\"nanika\"}\n")
loop do
	str = gets.chomp
	if str == "close"
		client.close
		break
	else
		client.write(str)
		client.write('\n')
	end
end
