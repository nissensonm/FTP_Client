//Michael Nissenson
//CSS 432, Networking, Program 5: messages.cpp
//Created 06/04/2016
//Last Modified: 06/04/2016
//Purpose of this file is to handle messages received from server, this includes:
// 1. printData(): Output message from server to user
// 2. getDataFromServer(): get and store message from server
// 3. Parse the message from the server (based on the 3 number code)

#ifndef MESSAGES_CPP
#define MESSAGES_CPP

#include "ftpclient.cpp"

//Prints message from server
int printData(char *output)
{
	if (output == NULL) //If null, return -1 and output nothing
	{
		return -1;
	}
	cout << output;
	return 0;
}

//getData from the server just takes the message received and prints it. 
int getDataFromServer(int clientSd)
{
	struct pollfd ufds;

	ufds.fd = clientSd;               // a socket descriptor to examine for read
	ufds.events = POLLIN;             // check if sd is ready to read
	ufds.revents = 0;                 // simply zero-initialized
	int val = 0;					  // We want the while loop below to run at least once
	buff = new char[BUFF_SIZE];
	bool readAtLeastOnce = false;
	while (val > 0 || readAtLeastOnce == false)
	{ 
		val = poll( &ufds, 1, 1000 ); // poll this socket for 1000msec (=1sec)
		int nread = 0;
		if ( val > 0 ) // the socket is ready to read
		{                  
			readAtLeastOnce = true;
			nread = read( clientSd, buff, BUFF_SIZE ); // Keep track of # of reads that took place
		}
	}
	printData(buff);
	return parseServerData(buff);
}

//Used to parse the data received from server
//The value it returns should correspond to a constant value found 
//In the FTP Constants above.
int parseServerData(char *dataFromServer)
{
	if (dataFromServer == NULL)
	{
		return -1;
	}
	char parseData[4]; //Prepare a c string with an extra slot for return character
	strncpy(parseData,dataFromServer,3); //Copy first three values
	int parseInt = atoi(parseData);	//Convert it to an int so we can do comparisons
	return parseInt;
}


#endif