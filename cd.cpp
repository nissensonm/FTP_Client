//Michael Nissenson
//CSS 432, Networking, Program 5: cd.cpp
//Created 06/05/2016
//Last Modified: 06/05/2016
// This file handles the cd command, 
// after getting cd + argument from take input
#ifndef CD_CPP
#define CD_CPP

#include "ftpclient.cpp"

void cdCmd(int socketDesc, string directory)
{
	const char *dir = directory.c_str();
	
	char command[S_BUFF_SIZE];         // Where we store the user's command
	
	char toSendCommand[S_BUFF_SIZE]; //toSendCommand is used to create the actual command sent
	strcpy(toSendCommand, "CWD "); //Username to log in with
	strcat(toSendCommand, dir);
	strcat(toSendCommand, "\r\n"); //Append crlf delimiter
	
	int retWrite = write(socketDesc, toSendCommand, strlen(toSendCommand));
}

#endif
