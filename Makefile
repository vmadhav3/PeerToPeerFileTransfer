all:
	gcc server.c -lpthread -o ../server
	gcc client.c -lpthread -o ../client -lcrypto -lssl
	
	
clean:
	rm -rf *o server
	rm -rf *o client

