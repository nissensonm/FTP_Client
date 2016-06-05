//Michael Nissenson
//CSS 432, Networking, Program 5: syst.cpp
//Created 06/04/2016
//Last Modified: 06/04/2016
//This function is called when the interpreter loop wants to SEND the syst function

#ifndef SYST_CPP
#define SYST_CPP

#include "ftpclient.cpp"

//Used to send data to server for userName; called when code 220 is received.
void syst(int clientSd)
{
	char toSendCommand[S_BUFF_SIZE]; //toSendCommand is used to create the actual command sent
	strcpy(toSendCommand, "SYST"); // send Syst to server
	strcat(toSendCommand, "\r\n"); //Append crlf delimiter

	int retWrite = write(clientSd, toSendCommand, strlen(toSendCommand));
}


#endif