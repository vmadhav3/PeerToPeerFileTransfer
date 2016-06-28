
 
#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/dir.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <sys/param.h>

//the thread function
void *connection_handler(void *);

int server = 5;

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("SERVER SIDE :");
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 3456 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 10);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

	int iclient = 0;
 while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
	iclient = iclient + 1;
        printf("\nNew Client %d accepted",iclient);
         
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
         
        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("\ncould not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        puts("\nHandler assigned");
    }

if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
     
    return 0;
}

void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[256];
     memset(client_message,'\0',sizeof(client_message));
    //Receive a message from client
	while(1)
        {    
	read_size = recv(sock , client_message , sizeof(client_message) , 0) ;
   
      		if(strcmp(client_message,"TRACKER")==0)
		{
			server = handle_tracker(sock);
		}
		else if (strcmp(client_message,"LIST")==0)
		{	
			server = handle_list(sock);
		}
        memset(client_message,'\0',sizeof(client_message));
   }
	
	free(socket_desc);
     
    return 0;
}

int handle_tracker(int sock)
{
	 char server_message[100];
	 handle_create();
	strcpy(server_message,"\nTRACKER CREATED/UPDATED");
	 write(sock , server_message , strlen(server_message));
		server = server - 1;
		return server;

}

int handle_list(int sock)
{
	 char server_message[1000];
		if(server > 0)
		{	
			strcpy(server_message,"Requesting Files...");
	 		write(sock , server_message , strlen(server_message));
			return server;
		}
		if(server == 0)
		{
			strcpy(server_message,"picture-wallpaper.jpg");
	 		write(sock , server_message , strlen(server_message));
			return server;
		}

}
handle_create()
{
	FILE *fp;
	char detail[500];
	memset(detail,'\0',sizeof(detail));
	fp = fopen("test_server/picture-wallpaper.track","ab+");
	strcpy(detail,"picture-wallpaper.jpg-35735-picture file-127.0.0.1-3456-a928c301531e5ee455b34436c5c64af1-");
	fwrite(detail,strlen(detail),1,fp);
	fclose(fp);

}

handle_createtracker_req(int connfd)
{
	int bytesReceived = 0;
	char recvBuff[1024];
	char fname[20];
	const char s[2] = ".";
    DIR  *d;
    struct dirent *dir;


   	char *token[20];
	memset(recvBuff, '0', sizeof(recvBuff));


         d = opendir("trackerdir");
        FILE *fp;
         fp = fopen("trackerdir/track1.txt", "ab"); 
    if(NULL == fp)
    {
        printf("Error opening file");
        return 1;
    }

    //memset(recvBuff, '0', sizeof(recvBuff));
    /* Receive data in chunks of 256 bytes */
	int i;   
	 while((bytesReceived = read(connfd, recvBuff, 1024)) > 0)
    {
       printf("Bytes received %d\n",bytesReceived);    
	
	// recvBuff[n] = 0;
        fwrite(recvBuff, 1,bytesReceived,fp);
	i = i+1;	
	token[i] = strtok(recvBuff, s);
        // printf("%s \n", recvBuff);
    }
    //opendir("trackerdir");
    char strack[30];
    strcpy(strack,"trackerdir/");
	strcat(token[1],".track");
    strcat(strack,token[1]);
    printf("%s",token[1]);
	rename("trackerdir/track1.txt", strack);
    printf("\n <createtracker success>\n");

    if(bytesReceived < 0)
    {
        printf("\n Read Error \n");
        printf("\n <createtracker Failed> \n");
    }
	

        close(connfd);
        sleep(1);
    	
}

handle_updatetracker_req(int connfd, char read_msg[25])
{
	int bytesReceived = 0;
	char recvBuff[1024];
	
	FILE *fp1;
	DIR  *d;
    	struct dirent *dir;
    	d = opendir("trackerdir");
	char msgq1[20];
	char newmsg1[35];
	int l = strlen(read_msg);
	strncpy(msgq1,read_msg+7,l);
	strcpy(newmsg1,"trackerdir/");  
        strcat(newmsg1,msgq1);
	printf("%s",newmsg1);
        /* Open the file that we wish to transfer */
        FILE *fp = fopen(newmsg1,"ab");
        if(fp==NULL)
        {
            printf("File open error");
            return 1;   
        }   

		 
	 while((bytesReceived = read(connfd, recvBuff, 15)) > 0)
    {
       printf("Bytes received %d\n",bytesReceived);    
	
	// recvBuff[n] = 0;
        fwrite(recvBuff, 1,bytesReceived,fp);

	}

	if(bytesReceived < 0)
    {
        printf("\n Read Error \n");
        printf("\n <createtracker Failed> \n");
    }
	

        close(connfd);
        sleep(1);



}


	
