//Michael Nissenson
//CSS 432, Networking, Program 5: ftpclient
//Created 06/04/2016
//Last Modified: 06/04/2016

#ifndef FTPCLIENT_CPP
#define FTPCLIENT_CPP

#include "ftpclient.h"
#include "messages.cpp"
#include "user.cpp"
#include "pass.cpp"
#include "interpreter.cpp"
#include "syst.cpp"
#include "takeinput.cpp"

//Main is intended to just establish the initial connection
int main(int argc, char *argv[])
{
	if (argc != 2 )			//Expected use is ./programName [hostname]
	{
		cerr << "usage: " << argv[0] << " hostname" << endl;
		return -1;
	}
	
	//set ftp server's; error handling done when attempting to connect
	char* tcpServer = argv[1]; 
	
	//Retrieve hostent structure corresponding to IP name
	struct hostent* host = gethostbyname(tcpServer);

	//Declare sockaddr_in structure
    sockaddr_in sendSockAddr;
    bzero((char*)&sendSockAddr, sizeof(sendSockAddr)); //zero-initialize sendSockAddr
    sendSockAddr.sin_family = AF_INET; // Address Family Internet
    sendSockAddr.sin_addr.s_addr =
		inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    sendSockAddr.sin_port = htons(FTP_PORT_NUM);

	//Open a stream-oriented socket.
	int clientSd = socket(AF_INET, SOCK_STREAM, 0);
	
	//Connect to the server; rc used to test if connection was successful or not
	int rc = connect(clientSd, (sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
	if (rc < 0) //Either incorrect IP address or something else went wrong
	{
		cerr << "Connection Not Established" << endl;
		close (clientSd);
		return -1; 
	}

	cout << "ftp> "; //Output similar to how it looks like on the ftp client
	char command[S_BUFF_SIZE]; //Set up buffer to take user command
	cin.getline( command, S_BUFF_SIZE ); //Take input                      
	
	char parseCmd[S_BUFF_SIZE];
	strncpy(parseCmd,command,2); //First we check if the command was cd or ls
	cout << "PARSE: " << parseCmd << "!"<< endl;
	
	if (parseCmd == "ls")
	{
		cout << "Yep, they typed ls" << endl;
	}
	if (parseCmd == "cd")
	{
		cout << "Typed cd" << endl;
	}
	
	
	//interpLoop(clientSd, argv);

	
	close (clientSd); //Close client socket to try and free it sooner
	return 0;
}

#endif























