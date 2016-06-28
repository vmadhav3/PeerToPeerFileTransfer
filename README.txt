I.Introduction:
The peer to peer file sharing protocol is based on the bit torrent protocol. 
The tracker server keeps the track of which the peers are sharing the files and what files are being shared by the peers.
The peers contact the tracker server to create the tracker entry and update its sharing status.
 Only the peers with full files can send create tracker to the tracker server. 
Other peers download the shared files.  The peers also request the tracker files maintained by the server.
 Also it can request the server for a particular tracker file. As soon as the tracker file is received,
the requesting peer redirects its connection to the selected peers and the download takes place.

CodeDesign:

a.Server:
The server is launched with the IP local host. The listening port is “3456”. 
The server program has the connection handler to make the TCP connection and the thread creation program to
 create 10 threads for the 10 clients. It has got the create tracker program so that the clients with files
 make the tracker file. The server code also has the LIST function for the receiving clients to execute in server.
b.Send Client:
The send client programmed to connect to the server. The sending clients send message to create tracker and update 
tracker to the server. Then the server waits for incoming connections. It creates threads for each incoming connection. 
Then executes the File Transfer function. The sending clients have 20% of the entire file each. 
This 20% is divided into four parts of 5%. The sending clients send 5% of the file at any time.
c.Receiving clients:
The receiving clients connect to the server. The clients create socket connection with the sending clients. 
It executes the GET function to receive the file chunks. It then checks the MD5 of the received files.

Running Guide:

The code is written to run in Ubuntu platform. 
Before running the program, create two folders. test_server and test_clients. In test_clients folder create 10 client folders client_1 to client_10.  In first five client folders client_1 to client_5 place the picture “picture-wallpaper.jpg”. 
Now to run the server and client programs execute the following steps:
1.	Open a command prompt and go to the folder containing the client and server programs.
2.	Compile and execute the server program first 
gcc server.c -lpthread -o server
./server
3.	Compile and execute the client program
a.	Receiving clients
gcc client.c -lpthread -o client -lcrypto -lssl
./client LIST C6
./client LIST C7
./client LIST C8
./client LIST C9
./client LIST C10

b.	Sending clients
./client TRACKER C1
./client TRACKER C2
./client TRACKER C3
./client TRACKER C4
./client TRACKER C5
After executing the program check the client folders client_6 to client_10 to see the downloaded file.





