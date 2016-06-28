/*
    C ECHO client example using sockets
*/
#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>//socket programming
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/dir.h>
#include <netinet/in.h>
#include <dirent.h>
#include <sys/param.h>
#include <openssl/md5.h>//md5 calculation

void *c1_handler(void *);

void *c2_handler(void *);

void *c3_handler(void *);

void *c4_handler(void *);

void *c5_handler(void *);

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000]; 
    char *arg1 = argv[1];
    char *arg2 = argv[2];
    printf("\n MESSAGE TYPE : %s\n",arg1);
	printf("\n FROM CLIENT  : %s\n",arg2);
   //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts(" Main Server Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 3456 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    puts("Connected\n");  

	
    //keep communicating with server
       
   
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 	if(strcmp(arg1,"TRACKER")==0)//SENDING CLIENTS CODE
	{
		if( send(sock , arg1 , strlen(arg1) , 0) < 0)
        	{
            		puts("Send failed");
            
        	}
		int bytesReceived;
		char recvBuff[256];
		memset(recvBuff,'\0',sizeof(recvBuff));
		
		bytesReceived = read(sock, recvBuff, sizeof(recvBuff));
       		printf("\n %s\n",recvBuff);
	
		int rclient1 = 5;
		int i = 0;

		int socket_desc1 , client_sock1 , c1 , *new_sock1;
    		struct sockaddr_in server1 , client1;
     		
		int socket_desc2 , client_sock2 , c2 , *new_sock2;
    		struct sockaddr_in server2 , client2;

		int socket_desc3 , client_sock3 , c3 , *new_sock3;
    		struct sockaddr_in server3 , client3;

		int socket_desc4 , client_sock4 , c4 , *new_sock4;
    		struct sockaddr_in server4 , client4;
		
		int socket_desc5 , client_sock5 , c5 , *new_sock5;
    		struct sockaddr_in server5 , client5;
		
		pthread_t client_thread1[5];
        	pthread_t client_thread2[5];
		pthread_t client_thread3[5];
		pthread_t client_thread4[5];
		pthread_t client_thread5[5];
				

		if(strcmp(arg2,"C1")==0)  //client number 1
		{	//Create socket
    			socket_desc1 = socket(AF_INET , SOCK_STREAM , 0);
    			if (socket_desc1 == -1)
    			{
        			printf("Could not create socket");
    			}
    			puts("Sender Client 1");
     
    			//Prepare the sockaddr_in structure
    			server1.sin_family = AF_INET;
    			server1.sin_addr.s_addr = INADDR_ANY;
    			server1.sin_port = htons( 6361 );
     			
			//Bind
    			if( bind(socket_desc1,(struct sockaddr *)&server1 , sizeof(server1)) < 0)
    			{
        			perror("bind failed. Error");//print the error message
        		}
    			puts("To receive chunks of file receiving clients must bind ");
       			//Listen
    			listen(socket_desc1 , 5);
     
    			//Accept and incoming connection
    			puts("Waiting for incoming client requests...");
			
    			c1 = sizeof(struct sockaddr_in);
							
		}
		else if(strcmp(arg2,"C2")==0)  //client number 2
		{	//Create socket
    			socket_desc2 = socket(AF_INET , SOCK_STREAM , 0);
    			if (socket_desc2 == -1)
    			{
        			printf("Could not create socket");
    			}
    			puts("Sender Client 2");
     
    			//Prepare the sockaddr_in structure
    			server2.sin_family = AF_INET;
    			server2.sin_addr.s_addr = INADDR_ANY;
    			server2.sin_port = htons( 6362 );
     			
			//Bind
    			if( bind(socket_desc2,(struct sockaddr *)&server2 , sizeof(server2)) < 0)
    			{
        			perror("bind failed. Error");//print the error message
        		}
    			puts("To receive chunks of file receiving clients must bind ");
       			//Listen
    			listen(socket_desc2 , 5);
     
    			//Accept and incoming connection
    			puts("Waiting for incoming client requests...");
	
    			c2 = sizeof(struct sockaddr_in);
					
		}
		else if(strcmp(arg2,"C3")==0)  //client number 3
		{	//Create socket
    			socket_desc3 = socket(AF_INET , SOCK_STREAM , 0);
    			if (socket_desc3 == -1)
    			{
        			printf("Could not create socket");
    			}
    			puts("Sender Client 3");
     
    			//Prepare the sockaddr_in structure
    			server3.sin_family = AF_INET;
    			server3.sin_addr.s_addr = INADDR_ANY;
    			server3.sin_port = htons( 6363 );
     			
			//Bind
    			if( bind(socket_desc3,(struct sockaddr *)&server3 , sizeof(server3)) < 0)
    			{
        			perror("bind failed. Error");//print the error message
        		}
    			puts("To receive chunks of file receiving clients must bind ");
       			//Listen
    			listen(socket_desc3 , 5);
     
    			//Accept and incoming connection
    			puts("Waiting for incoming client requests...");
	
    			c3 = sizeof(struct sockaddr_in);
					
		}		

		else if(strcmp(arg2,"C4")==0)  //client number 4
		{	//Create socket
    			socket_desc4 = socket(AF_INET , SOCK_STREAM , 0);
    			if (socket_desc4 == -1)
    			{
        			printf("Could not create socket");
    			}
    			puts("Sender Client 4");
     
    			//Prepare the sockaddr_in structure
    			server4.sin_family = AF_INET;
    			server4.sin_addr.s_addr = INADDR_ANY;
    			server4.sin_port = htons( 6364 );
     			
			//Bind
    			if( bind(socket_desc4,(struct sockaddr *)&server4 , sizeof(server4)) < 0)
    			{
        			perror("bind failed. Error");//print the error message
        		}
    			puts("To receive chunks of file receiving clients must bind ");
       			//Listen
    			listen(socket_desc4 , 5);
     
    			//Accept and incoming connection
    			puts("Waiting for incoming client requests...");
	
    			c4 = sizeof(struct sockaddr_in);
					
		}
		
		else if(strcmp(arg2,"C5")==0)  //client number 5
		{	//Create socket
    			socket_desc5 = socket(AF_INET , SOCK_STREAM , 0);
    			if (socket_desc5 == -1)
    			{
        			printf("Could not create socket");
    			}
    			puts("Sender Client 5");
     
    			//Prepare the sockaddr_in structure
    			server5.sin_family = AF_INET;
    			server5.sin_addr.s_addr = INADDR_ANY;
    			server5.sin_port = htons( 6365 );
     			
			//Bind
    			if( bind(socket_desc5,(struct sockaddr *)&server5 , sizeof(server5)) < 0)
    			{
        			perror("bind failed. Error");//print the error message
        		}
    			puts("To receive chunks of file receiving clients must bind ");
       			//Listen
    			listen(socket_desc5 , 5);
     
    			//Accept and incoming connection
    			puts("Waiting for incoming client requests...");
	
    			c5 = sizeof(struct sockaddr_in);
					
		}
///////////////////////TO CONNECT TO EACH SENDER CLIENT AND CREATE TRACKER////////////////////////////////////////////////////////////
		while ((((((client_sock1 = accept(socket_desc1, (struct sockaddr *)&client1, (socklen_t*)&c1)) && (client_sock2 = accept(socket_desc2, (struct sockaddr *)&client2, (socklen_t*)&c2))) && (client_sock3 = accept(socket_desc3, (struct sockaddr *)&client3, (socklen_t*)&c3))) && (client_sock4 = accept(socket_desc4, (struct sockaddr *)&client4, (socklen_t*)&c4))) && (client_sock5 = accept(socket_desc5, (struct sockaddr *)&client5, (socklen_t*)&c5))) && i < 5 )

    			{	i++;//Number of clients joining in.
				rclient1 = rclient1 + 1;
	       			printf("\n Sending Client %d data.....",rclient1);

                     		new_sock1 = malloc(1);
        			*new_sock1 = client_sock1;
				new_sock2 = malloc(1);
        			*new_sock2 = client_sock2;
				new_sock3 = malloc(1);
        			*new_sock3 = client_sock3;
				new_sock4 = malloc(1);
        			*new_sock4 = client_sock4;
				new_sock5 = malloc(1);
        			*new_sock5 = client_sock5;
												
				

				if((((client_sock1 > 0 && client_sock2 < 0) && (client_sock3 < 0)) && (client_sock4 < 0)) && (client_sock5 < 0))
				{
					pthread_create( &client_thread1[i] , NULL ,  c1_handler , (void*) new_sock1);//thread for sender 1
				}								
				if((((client_sock2 > 0 && client_sock1 < 0) && (client_sock3 < 0)) && (client_sock4 < 0)) && (client_sock5 < 0))
        			  {	
					pthread_create( &client_thread2[i] , NULL ,  c2_handler , (void*) new_sock2);//thread for sender 2
					
				  }
				if((((client_sock3 > 0 && client_sock1 < 0) && (client_sock2 < 0)) && (client_sock4 < 0)) && (client_sock5 < 0))
        			  {	
					pthread_create( &client_thread3[i] , NULL ,  c3_handler , (void*) new_sock3);//thread for sender 3
					
				  }	
				  
				if((((client_sock4 > 0 && client_sock1 < 0) && (client_sock2 < 0)) && (client_sock3 < 0)) && (client_sock5 < 0))
        			  {	
					pthread_create( &client_thread4[i] , NULL ,  c4_handler , (void*) new_sock4);//thread for sender 4
					
				  }
				
				if((((client_sock5 > 0 && client_sock1 < 0) && (client_sock2 < 0)) && (client_sock3 < 0)) && (client_sock4 < 0))
        			  {	
					pthread_create( &client_thread5[i] , NULL ,  c5_handler , (void*) new_sock5);//thread for sender 5
					
				  }
					pthread_join( client_thread1[i] , NULL);
					pthread_join( client_thread2[i] , NULL);
        				pthread_join( client_thread3[i] , NULL);
					pthread_join( client_thread4[i] , NULL);
					pthread_join( client_thread5[i] , NULL);
										
				if(i==5)
				{
					exit(0);
				}
			 }
			
				
	}//SENDING CLIENTS MAIN CODE ENDS HERE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	else if(strcmp(arg1,"LIST")==0)//RECEIVING CLIENTS CODE
	{	int check = 0;
		char recvBuff[256];
		while(check < 1)//To keep listening to server till the sending clients connect to it and advertise data.
		{		
			if( write(sock , arg1 , strlen(arg1)) < 0)
        		{
            		  	puts("Send failed");
            
        		}
			int bytesReceived;
			memset(recvBuff,'\0',sizeof(recvBuff));
			bytesReceived = read(sock, recvBuff, sizeof(recvBuff));
         		printf("\n %s\n",recvBuff);
			if(strcmp(recvBuff,"picture-wallpaper.jpg")!=0)
				{
					check = 0;
					memset(recvBuff,'\0',sizeof(recvBuff));
					
				}
			else
				{
					check = 1;
					break;
				}
			sleep(10);
			
		}
		
		if(strcmp(recvBuff,"picture-wallpaper.jpg")==0)//to connect to sending clients and get data(file)
		{
			printf("\n GET %s\n",recvBuff);
			char f1[100];
			memset(f1,'\0',sizeof(f1));
			if(strcmp(arg2,"C6")==0)
			{
				strcpy(f1,"test_clients/client_6/picture-wallpaper.jpg");
			}
			else if(strcmp(arg2,"C7")==0)
			{
				strcpy(f1,"test_clients/client_7/picture-wallpaper.jpg");
			}
			else if(strcmp(arg2,"C8")==0)
			{
				strcpy(f1,"test_clients/client_8/picture-wallpaper.jpg");
			}
			else if(strcmp(arg2,"C9")==0)
			{
				strcpy(f1,"test_clients/client_9/picture-wallpaper.jpg");
			}
			else if(strcmp(arg2,"C10")==0)
			{
				strcpy(f1,"test_clients/client_10/picture-wallpaper.jpg");
			}
	
			//socket to connect to client 1
			 int sock6;
            		 struct sockaddr_in server6;
            		 char message6[1000] , server_reply6[2000];
    		
             			//Create socket
            			sock6 = socket(AF_INET , SOCK_STREAM , 0);
            			if (sock6 == -1)
                		{
                    			printf("Could not create socket");
                		}
            			puts("\nThread created with Sender client 1\n");
     
            			server6.sin_addr.s_addr = inet_addr("127.0.0.1");
            			server6.sin_family = AF_INET;
            			server6.sin_port = htons( 6361 );
 
            			//Connect to remote server
            			if (connect(sock6 , (struct sockaddr *)&server6 , sizeof(server6)) < 0)
                		{
                    			perror("connect failed. Error");
		
                		}
     	    			else{
            				puts("Connected\n");
				    }
				

			 //socket to connect to client 2
            		int sock7;
           		struct sockaddr_in server7;
            		char message7[1000] , server_reply7[2000];
    
             			//Create socket
            			sock7 = socket(AF_INET , SOCK_STREAM , 0);
            			if (sock7 == -1)
                		{
                    			printf("Could not create socket");
                		}
            			puts("\nThread created with Sender client 2");
     
            			server7.sin_addr.s_addr = inet_addr("127.0.0.1");
            			server7.sin_family = AF_INET;
            			server7.sin_port = htons(6362);
 
            			//Connect to remote server
            			if (connect(sock7 , (struct sockaddr *)&server7 , sizeof(server7)) < 0)
                		{
                    			perror("connect failed. Error");
                    		}
     				else
				{
            				puts("Connected\n");
            			}

			//socket to connect to client 3
			int sock8;
            		 struct sockaddr_in server8;
            		 char message8[1000] , server_reply8[2000];
    		
             			//Create socket
            			sock8 = socket(AF_INET , SOCK_STREAM , 0);
            			if (sock8 == -1)
                		{
                    			printf("Could not create socket");
                		}
            			puts("\nThread created with Sender client 3\n");
     
            			server8.sin_addr.s_addr = inet_addr("127.0.0.1");
            			server8.sin_family = AF_INET;
            			server8.sin_port = htons( 6363 );
 
            			//Connect to remote server
            			if (connect(sock8 , (struct sockaddr *)&server8 , sizeof(server8)) < 0)
                		{
                    			perror("connect failed. Error");
		
                		}
     	    			else{
            				puts("Connected\n");
				    }
			
			//socket to connect to client 4
			 int sock9;
            		 struct sockaddr_in server9;
            		 char message9[1000] , server_reply9[2000];
    		
             			//Create socket
            			sock9 = socket(AF_INET , SOCK_STREAM , 0);
            			if (sock9 == -1)
                		{
                    			printf("Could not create socket");
                		}
            			puts("\nThread created with Sender client 4\n");
     
            			server9.sin_addr.s_addr = inet_addr("127.0.0.1");
            			server9.sin_family = AF_INET;
            			server9.sin_port = htons( 6364 );
 
            			//Connect to remote server
            			if (connect(sock9 , (struct sockaddr *)&server9 , sizeof(server9)) < 0)
                		{
                    			perror("connect failed. Error");
		
                		}
     	    			else{
            				puts("Connected\n");
				    }
				
			//socket to connect to client 5
			int sock10;
            		 struct sockaddr_in server10;
            		 char message10[1000] , server_reply10[2000];
    		
             			//Create socket
            			sock10 = socket(AF_INET , SOCK_STREAM , 0);
            			if (sock10 == -1)
                		{
                    			printf("Could not create socket");
                		}
            			puts("\nThread created with Sender client 5\n");
     
            			server10.sin_addr.s_addr = inet_addr("127.0.0.1");
            			server10.sin_family = AF_INET;
            			server10.sin_port = htons( 6365 );
 
            			//Connect to remote server
            			if (connect(sock10 , (struct sockaddr *)&server10 , sizeof(server10)) < 0)
                		{
                    			perror("connect failed. Error");
		
                		}
     	    			else{
            				puts("Connected\n");
				    }
			

				char client_msg[256];
				memset(client_msg,'\0',sizeof(client_msg));
				strcpy(client_msg,"file1");//request 1% to 20% of the file
				
				char client_msg1[256];
				memset(client_msg1,'\0',sizeof(client_msg1));
				strcpy(client_msg1,"file2");//request 21% to 40% of the file 
				
				char client_msg2[256];
				memset(client_msg2,'\0',sizeof(client_msg2));
				strcpy(client_msg2,"file3");//request 41% to 60% of the file
				
				char client_msg3[256];
				memset(client_msg3,'\0',sizeof(client_msg3));
				strcpy(client_msg3,"file4");//request 61% to 80% of the file
				
				char client_msg4[256];
				memset(client_msg4,'\0',sizeof(client_msg4));
				strcpy(client_msg4,"file5");//request 81% to 100% of the file
								

				if( send(sock6 , client_msg , strlen(client_msg), 0 ) < 0)// message to send first chunk
        			{
            				puts("send failed");
				}
								
				if( send(sock7 , client_msg1 , strlen(client_msg1), 0 ) < 0)// message to send second chunk
        			{
            				puts("send failed");
				}
								
				if( send(sock8 , client_msg2 , strlen(client_msg2), 0 ) < 0)// message to send third chunk
        			{
            				puts("send failed");
				}
				
				if( send(sock9 , client_msg3 , strlen(client_msg3), 0 ) < 0)// message to send fourth chunk
        			{
            				puts("send failed");
				}

				if( send(sock10 , client_msg4 , strlen(client_msg4), 0 ) < 0)// message to send fifth chunk
        			{
            				puts("send failed");
				}

				int bytesReceived;
				char cmsg[256];
				memset(cmsg,'\0',sizeof(cmsg));

				char buffer[1];
				FILE *fp1;
				fp1 = fopen(f1,"ab+");
				while(bytesReceived = recv(sock6, buffer, sizeof(buffer),0) > 0)
				  {  
					fwrite(buffer, 1, 1, fp1);//writing the 1st chunk
				  }
				fclose(fp1);
         			
			        int bytesReceived2;
				char cmsg2[256];
				memset(cmsg2,'\0',sizeof(cmsg2));

				char buffer2[1];
				FILE *fp2;
				fp2 = fopen(f1,"ab+");
				while(bytesReceived2 = recv(sock7, buffer2, sizeof(buffer2),0) > 0)
				  {  
					fwrite(buffer2, 1, 1, fp2);//writing the 2nd chunk
				  }
				fclose(fp2);

				int bytesReceived3;
				char cmsg3[256];
				memset(cmsg3,'\0',sizeof(cmsg3));

				char buffer3[1];
				FILE *fp3;
				fp3 = fopen(f1,"ab+");
				while(bytesReceived3 = recv(sock8, buffer3, sizeof(buffer3),0) > 0)
				  {  
					fwrite(buffer3, 1, 1, fp3);//writing the 3rd chunk
				  }
				fclose(fp3);

				int bytesReceived4;
				char cmsg4[256];
				memset(cmsg4,'\0',sizeof(cmsg3));

				char buffer4[1];
				FILE *fp4;
				fp4 = fopen(f1,"ab+");
				while(bytesReceived4 = recv(sock9, buffer4, sizeof(buffer4),0) > 0)
				  {  
					fwrite(buffer4, 1, 1, fp4);//writing the 4th chunk
				  }
				fclose(fp4);

				int bytesReceived5;
				char cmsg5[256];
				memset(cmsg5,'\0',sizeof(cmsg5));

				char buffer5[1];
				FILE *fp5;
				fp5 = fopen(f1,"ab+");
				while(bytesReceived5 = recv(sock10, buffer5, sizeof(buffer5),0) > 0)
				  {  
					fwrite(buffer5, 1, 1, fp5);//writing the 5th chunk
				  }
				fclose(fp5);
         			
				shutdown(sock6, 2);
				
				shutdown(sock7, 2);
			
				shutdown(sock8, 2);

				shutdown(sock9, 2);
				
				shutdown(sock10, 2);


				printf("\n FILE TRANSFER COMPLETE\n");

				//Calculate and check md5sum
    				int q;
    				FILE *inFile;
    				inFile = fopen (f1, "rb");
    				MD5_CTX mdContext;
    				int bytes;
    				unsigned char data[1024];
    				unsigned char c[MD5_DIGEST_LENGTH];
   				MD5_Init (&mdContext);
    				while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        				MD5_Update (&mdContext, data, bytes);
    				MD5_Final (c,&mdContext);
				
				printf("\n Hi, I am client %s, I have received the file correctly\n",arg2);
							
		}
	}
					
}
	
void *c1_handler(void *socket_desc)//Thread function to transfer 1st chunk by sending client 1
{   //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size,piece1,piece2,piece3;
    char message[256] , client_message[256];
    memset(client_message,'\0',sizeof(client_message));
    
	FILE *fp;
	fp = fopen("test_clients/client_1/picture-wallpaper.jpg","rb+");
	//handle_md5("test_clients/client_1/picture-wallpaper.jpg");
	int fsize,start,end,fchunk,nfchunk;
	fsize = filesize(fp);
	//printf("\n File Size :%d\n",fsize);
    	fchunk = fsize/5;
    	start = 0;
    	nfchunk = fchunk/4;
	piece1 = nfchunk+start;
    	end = fchunk;
	//printf("\n END Size :%d\n",end);
	char buffer[1];

	read_size = recv(sock , client_message , sizeof(client_message) , 0) ;
   	if(strcmp(client_message,"file1")==0)
	{	
		if(start == 0)
		{
			printf("\n Transferring 1 to 5 percent of the file\n");
			sleep(2);
		}
		/* Seek to the beginning of the file */
   		fseek(fp, SEEK_SET, 0);
		/* Open file for both reading and writing */
		while(start <= end)
		{
	 		fseek( fp, start, SEEK_SET );
			/* Read and display data */
   			fread(buffer, 1, 1, fp);
			read_size = send(sock , buffer , sizeof(buffer) , 0);
			start = start + 1;
			if(start == piece1)
			{
				printf("\n Transferring 6 to 10 percent of the file\n");
				piece2 = piece1 + nfchunk;
				sleep(2);
			}
			if(start == piece2 )
			{
				printf("\n Transferring 11 to 15 percent of the file\n");
				piece3 = piece2 + nfchunk;
				sleep(2);
			}
			if(start == piece3 )
			{
				printf("\n Transferring 16 to 20 percent of the file\n");
				sleep(2);
			}
			
  		}
		fclose(fp);
	}
	memset(client_message,'\0',sizeof(client_message));
		 
	free(socket_desc);
      		
}

void *c2_handler(void *socket_desc)//Thread function to transfer 2nd chunk by sending client 2
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size,piece1,piece2,piece3;
    char message[256] , client_message[256];
    memset(client_message,'\0',sizeof(client_message));

    FILE *fp;
    fp = fopen("test_clients/client_2/picture-wallpaper.jpg","rb+");
   // handle_md5("test_clients/client_2/picture-wallpaper.jpg");
    int fsize,start,end,fchunk,nfchunk;
    fsize = filesize(fp);
    //printf("\n File Size :%d\n",fsize);
    fchunk = fsize/5;
    start = fchunk+1;
    nfchunk = fchunk/4;
    piece1 = nfchunk+start;
    end = 2*fchunk;
    //printf("\n END Size :%d\n",end);
    char buffer[1];


    read_size = recv(sock , client_message , sizeof(client_message) , 0) ;
    if(strcmp(client_message,"file2")==0)
    {	
	if(start == fchunk+1)
		{
			printf("\n Transferring 21 to 25 percent of the file\n");
			sleep(2);
		}
	/* Seek to the beginning of the file */
	fseek(fp, SEEK_SET, 0);
	/* Open file for both reading and writing */
 	while(start <= end)
        {
		fseek( fp, start, SEEK_SET );
		/* Read and display data */
   		fread(buffer, 1, 1, fp);
		read_size = send(sock , buffer , sizeof(buffer) , 0);
		start = start + 1;
		if(start == piece1)
		{
			printf("\n Transferring 26 to 30 percent of the file\n");
			piece2 = piece1 + nfchunk;
			sleep(2);
		}
		if(start == piece2 )
		{
			printf("\n Transferring 31 to 35 percent of the file\n");
			piece3 = piece2 + nfchunk;
			sleep(2);
		}
		if(start == piece3 )
		{
			printf("\n Transferring 36 to 40 percent of the file\n");
			sleep(2);
		}
  	 }
	fclose(fp);
    }
    memset(client_message,'\0',sizeof(client_message));
		 
    free(socket_desc);
}


void *c3_handler(void *socket_desc)//Thread function to transfer 3rd chunk by sending client 3
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size,piece1,piece2,piece3;
    char message[256] , client_message[256];
    memset(client_message,'\0',sizeof(client_message));

    FILE *fp;
    fp = fopen("test_clients/client_3/picture-wallpaper.jpg","rb+");
    //handle_md5("test_clients/client_3/picture-wallpaper.jpg");
    int fsize,start,end,fchunk,nfchunk;
    fsize = filesize(fp);
    //printf("\n File Size :%d\n",fsize);
    fchunk = fsize/5;
    start = (2*fchunk)+1;
    nfchunk = fchunk/4;
    piece1 = nfchunk+start;
    end = 3*fchunk;
    //printf("\n END Size :%d\n",end);
    char buffer[1];


    read_size = recv(sock , client_message , sizeof(client_message) , 0) ;
    if(strcmp(client_message,"file3")==0)
    {	
	if(start == ((2*fchunk)+1))
		{
			printf("\n Transferring 41 to 45 percent of the file\n");
			sleep(2);
		}
		
	/* Seek to the beginning of the file */
	fseek(fp, SEEK_SET, 0);
	/* Open file for both reading and writing */
 	while(start <= end)
        {
		fseek( fp, start, SEEK_SET );
		/* Read and display data */
   		fread(buffer, 1, 1, fp);
		read_size = send(sock , buffer , sizeof(buffer) , 0);
		start = start + 1;
		if(start == piece1)
		{
			printf("\n Transferring 46 to 50 percent of the file\n");
			piece2 = piece1 + nfchunk;
			sleep(2);
		}
		if(start == piece2 )
		{
			printf("\n Transferring 51 to 55 percent of the file\n");
			piece3 = piece2 + nfchunk;
			sleep(2);
		}
		if(start == piece3 )
		{
			printf("\n Transferring 56 to 60 percent of the file\n");
			sleep(2);
		}
  	 }
	fclose(fp);
    }
    memset(client_message,'\0',sizeof(client_message));
		 
    free(socket_desc);
}


void *c4_handler(void *socket_desc)//Thread function to transfer 4th chunk by sending client 4
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size,piece1,piece2,piece3;
    char message[256] , client_message[256];
    memset(client_message,'\0',sizeof(client_message));

    FILE *fp;
    fp = fopen("test_clients/client_4/picture-wallpaper.jpg","rb+");
   // handle_md5("test_clients/client_4/picture-wallpaper.jpg");
    int fsize,start,end,fchunk,nfchunk;
    fsize = filesize(fp);
    //printf("\n File Size :%d\n",fsize);
    fchunk = fsize/5;
    start = (3*fchunk)+1;
    nfchunk = fchunk/4;
    piece1 = nfchunk+start;
    end = 4*fchunk;
    //printf("\n END Size :%d\n",end);
    char buffer[1];


    read_size = recv(sock , client_message , sizeof(client_message) , 0) ;
    if(strcmp(client_message,"file4")==0)
    {	
	if(start == ((3*fchunk)+1))
		{
			printf("\n Transferring 61 to 65 percent of the file\n");
			sleep(2);
		}
	
	/* Seek to the beginning of the file */
	fseek(fp, SEEK_SET, 0);
	/* Open file for both reading and writing */
 	while(start <= end)
        {
		fseek( fp, start, SEEK_SET );
		/* Read and display data */
   		fread(buffer, 1, 1, fp);
		read_size = send(sock , buffer , sizeof(buffer) , 0);
		start = start + 1;
		if(start == piece1)
		{
			printf("\n Transferring 66 to 70 percent of the file\n");
			piece2 = piece1 + nfchunk;
			sleep(2);
		}
		if(start == piece2 )
		{
			printf("\n Transferring 71 to 75 percent of the file\n");
			piece3 = piece2 + nfchunk;
			sleep(2);
		}
		if(start == piece3 )
		{
			printf("\n Transferring 76 to 80 percent of the file\n");
			sleep(2);
		}
  	 }
	fclose(fp);
    }
    memset(client_message,'\0',sizeof(client_message));
		 
    free(socket_desc);
}

void *c5_handler(void *socket_desc)//Thread function to transfer 5th chunk by sending client 5
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size,piece1,piece2,piece3;
    char message[256] , client_message[256];
    memset(client_message,'\0',sizeof(client_message));

    FILE *fp;
    fp = fopen("test_clients/client_5/picture-wallpaper.jpg","rb+");
    //handle_md5("test_clients/client_5/picture-wallpaper.jpg");
    int fsize,start,end,fchunk,nfchunk;
    fsize = filesize(fp);
    //printf("\n File Size :%d\n",fsize);
    fchunk = fsize/5;
    start = (4*fchunk)+1;
    nfchunk = fchunk/4;
    piece1 = nfchunk+start;
    end = fsize;
    //printf("\n END Size :%d\n",end);
    char buffer[1];


    read_size = recv(sock , client_message , sizeof(client_message) , 0) ;
    if(strcmp(client_message,"file5")==0)
    {	
	if(start == ((4*fchunk)+1))
		{
			printf("\n Transferring 81 to 85 percent of the file\n");
			sleep(2);
		}
	
	/* Seek to the beginning of the file */
	fseek(fp, SEEK_SET, 0);
	/* Open file for both reading and writing */
 	while(start <= end)
        {
		fseek( fp, start, SEEK_SET );
		/* Read and display data */
   		fread(buffer, 1, 1, fp);
		read_size = send(sock , buffer , sizeof(buffer) , 0);
		start = start + 1;
		if(start == piece1)
		{
			printf("\n Transferring 86 to 90 percent of the file\n");
			piece2 = piece1 + nfchunk;
			sleep(2);
		}
		if(start == piece2 )
		{
			printf("\n Transferring 91 to 95 percent of the file\n");
			piece3 = piece2 + nfchunk;
			sleep(2);
		}
		if(start == piece3 )
		{
			printf("\n Transferring 96 to 100 percent of the file\n");
			sleep(2);
		}
  	 }
	fclose(fp);
    }
    memset(client_message,'\0',sizeof(client_message));
		 
    free(socket_desc);
}


int filesize(FILE *fp)// function used in check_track function, this is used to calculate the file size
    { 
      int prev=ftell(fp);
     fseek(fp, 0L, SEEK_END);
     int sz=ftell(fp);
     fseek(fp,prev,SEEK_SET); //go back to where we were
     return sz;
    }

