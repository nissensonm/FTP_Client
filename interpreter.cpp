//Michael Nissenson
//CSS 432, Networking, Program 5: pass.cpp
//Created 06/04/2016
//Last Modified: 06/04/2016
//The main interpreter loop takes user input, sends that input,
//then waits for a reply from the server. It then decides which function to call
//based on the message received

#ifndef INTERPRETER_CPP
#define INTERPRETER_CPP

#include "ftpclient.cpp"
void interpLoop(int socketDesc, char *argv[])
{
	bool hasUserLoggedInYet = false; //Used so we know if we call the syst function after we successfully log in
	
	while(true)	//Main loop 
	{
		delete buff;
		buff = NULL;
		int serverCode = getDataFromServer(socketDesc);
		
		if (serverCode == READY_FOR_NEW_USER) //If code 220, enter userName
		{
			userName(socketDesc, argv[1]);
		}
		else if (serverCode == USER_OK_ENTER_PASSWORD) //If code 331, enter password
		{
			userPass(socketDesc);
		}
		else if (serverCode == USER_LOGGED_IN && hasUserLoggedInYet == false) //If user hasn't logged in yet, call syst
		{
			hasUserLoggedInYet = true;	
			syst(socketDesc);
		}
		else if (serverCode == SYST_RCVD) //Syst info received, print and take input
		{
			takeInput(socketDesc);
		}
		else if (serverCode == USER_LOGGED_IN && hasUserLoggedInYet == true)
		{
			cout << "ftp> ";
			char command[S_BUFF_SIZE];
			cin.getline( command, S_BUFF_SIZE ); //Take input
		}
		else if (serverCode == SYNTAX_ERROR)
		{
			takeInput(socketDesc);
		}
		else //If unhandled code, exit
		{
			cerr << "An unhandled code has been received. Press enter to continue. " << endl;
			cerr << "Code received: " << serverCode << endl;
			char command[S_BUFF_SIZE];
			cin.getline( command, S_BUFF_SIZE ); //Take input
		}
	
	

	}
}
#endif