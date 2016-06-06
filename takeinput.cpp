//Michael Nissenson
//CSS 432, Networking, Program 5: takeinput.cpp
//Created 06/04/2016
//Last Modified: 06/04/2016
//This file takes and parses input from the user. 

#ifndef TAKEINPUT_CPP
#define TAKEINPUT_CPP

#include "ftpclient.cpp"

void takeInput(int socketDesc)
{
	bool successfullInput = false; //Stay in the loop until we get a message to send.
	
	while (successfullInput == false)
	{
		stringstream ss; //String stream, used to parse input
		string parseCmd; //Where we store our input before parsing
		string cmd; //Where we store the command after parsing 
		string arg1; //Parse first argument into this
		string arg2; //parse second argument into this (if there are any 2nd arguments)
		
		cout << "ftp> "; //output similar to the FTP client on linux       
		getline(cin, parseCmd);
		
		ss.str(parseCmd); //input parseCmd into the string stream
		ss >> cmd >> arg1 >> arg2;
		
		if (cmd == "ls")
		{
			cout << "Yep, they typed ls" << endl;
		}
		else if (cmd == "cd")
		{
			if (arg1 == "") //No argument entered
			{
				cout << "(remote-directory) ";
				getline(cin, arg1);
				
				if (arg1 == "") //If the user just hits enter again
				{
					cout << "usage: cd remote-directory" << endl;
					continue;
				}
			}
			cdCmd(socketDesc, arg1);
			successfullInput = true;
		}
		else if (cmd == "get")
		{
			
		}
		else if (cmd == "put")
		{
			
		}
		else if (cmd == "close")
		{
			
		}
		else if (cmd == "quit")
		{
			quitCmd(socketDesc);
			successfullInput = true;
		}
		else if (cmd == "syst")
		{
			syst(socketDesc);
			successfullInput = true;
		}
		else
		{
			cout << "Unrecognized command." << endl;
			cout << "Please note that this FTP client will only handle the following commands:" << endl;
			cout << "cd subdir, ls, get file, put file, close, quit, open, and syst." << endl;
		}
		//cd subdir
		//ls
		//get filebuf
		//put filebuf
		//close
		//quit
	}
	
}

#endif