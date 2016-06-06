//Michael Nissenson
//CSS 432, Networking, Program 5: quit.cpp
//Created 06/05/2016
//Last Modified: 06/05/2016
// This file handles the quit command, 
// after getting quit from take input.

#ifndef QUIT_CPP
#define QUIT_CPP

#include "ftpclient.cpp"

void quitCmd(int socketDesc)
{
	wasQuitCalled = true; //A bool found in ftpclient.h. We know to quit the program if true. 
	
	char toSendCommand[S_BUFF_SIZE]; //toSendCommand is used to create the actual command sent
	strcpy(toSendCommand, "QUIT"); // send Syst to server
	strcat(toSendCommand, "\r\n"); //Append crlf delimiter
	
	int retWrite = write(socketDesc, toSendCommand, strlen(toSendCommand));
}

#endif
