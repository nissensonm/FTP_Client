//Michael Nissenson
//CSS 432, Networking, Program 5: pass.cpp
//Created 06/04/2016
//Last Modified: 06/04/2016
//This file takes and parses input from the user. 

#ifndef TAKEINPUT_CPP
#define TAKEINPUT_CPP

#include "ftpclient.cpp"

void takeInput(int socketDesc)
{
	cout << "ftp> "; //Output similar to how it looks like on the ftp client
	char command[S_BUFF_SIZE]; //Set up buffer to take user command
	cin.getline( command, S_BUFF_SIZE ); //Take input                      
	
	char parseCmd[S_BUFF_SIZE];
	strncpy(parseCmd,command,2); //First we check if the command was cd or ls
	
	if (parseCmd == "ls")
	{
		cout << "Yep, they typed ls" << endl;
	}
	if (parseCmd == "cd")
	{
		cout << "Typed cd" << endl;
	}
	cout << "They typed something I don't recognized" << endl;
	//cd subdir
	//ls
	//get filebuf
	//put filebuf
	//close
	//quit
	
}

#endif