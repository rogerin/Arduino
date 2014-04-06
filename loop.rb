require 'net/http'
# asd
while true	
	uri = URI('http://www.chupasecompanhia.com/ARDUINO/turnON.php?id=8&ip=n')
	Net::HTTP.get(uri)
end
