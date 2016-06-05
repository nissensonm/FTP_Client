//Michael Nissenson
//CSS 432, Networking, Program 5: pass.cpp
//Created 06/04/2016
//Last Modified: 06/04/2016
//This function is called when the server returns code 331

#ifndef PASS_CPP
#define PASS_CPP

#include "ftpclient.cpp"

//Used to enter password
void userPass(int clientSd)
{	
	cout << "Password: ";
	char command[S_BUFF_SIZE];         // Where we store the user's command
    cin.getline( command, S_BUFF_SIZE ); //Take input
	
	char toSendCommand[S_BUFF_SIZE]; //toSendCommand is used to create the actual command sent
	strcpy(toSendCommand, "PASS "); //Username to log in with
	strcat(toSendCommand, command);
	strcat(toSendCommand, "\r\n"); //Append crlf delimiter
	
	int retWrite = write(clientSd, toSendCommand, strlen(toSendCommand));
}

#endif