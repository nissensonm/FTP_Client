//Michael Nissenson
//CSS 432, Networking, Program 5: user.cpp
//Created 06/04/2016
//Last Modified: 06/04/2016
//This function is called when the interpreter gets code 220

#ifndef USER_CPP
#define USER_CPP

#include "ftpclient.cpp"

//Used to send data to server for userName; called when code 220 is received.
int userName(int clientSd, char *ipAddr)
{
	char *serverIp = ipAddr;     
    string userString( getlogin( ) ); //Get username logged in
    cout << "Name (" << serverIp << ":" << userString << "): "; //Display formatting found in ftp client
	
	char command[S_BUFF_SIZE];         // Where we store the user's command
    cin.getline(command, S_BUFF_SIZE); //Take input
	
	char toSendCommand[S_BUFF_SIZE]; //toSendCommand is used to create the actual command sent
	strcpy(toSendCommand, "USER "); //Username to log in with
	strcat(toSendCommand, command);
	strcat(toSendCommand, "\r\n"); //Append crlf delimiter
	
	int retWrite = write(clientSd, toSendCommand, strlen(toSendCommand));
	return 0;
}


#endif