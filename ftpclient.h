#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include <sys/types.h>    // socket, bind
#include <sys/socket.h>   // socket, bind, listen, inet_ntoa
#include <netinet/in.h>   // htonl, htons, inet_ntoa
#include <arpa/inet.h>    // inet_ntoa
#include <netdb.h>        // gethostbyname
#include <unistd.h>       // read, write, close
#include <stdio.h>	      // getlogin
#include <stdlib.h>	      // atoi 
#include <string.h>       // bzero
#include <netinet/tcp.h>  // SO_REUSEADDR
#include <sys/uio.h>      // writev
#include <sstream>		  // string stream in stringToInt helper method
#include <iostream>		  // endl and cout
#include <signal.h>		  // signal
#include <fcntl.h>		  // fcntl
#include <sys/poll.h> 	  // For poll()	
using namespace std;

//Forward Declarations for all functions found in program
int parseServerData(char *dataFromServer);
int getDataFromServer(int clientSd);
int printData(char *output);
void userPass(int clientSd);
int userName(int clientSd, char *ipAddr);
void syst(int clientSd);
void takeInput(int socketDesc);
void quitCmd(int socketDesc);
void cdCmd(int socketDesc, string directory);

//Declaring constants to make code easier to read
const int FTP_PORT_NUM = 21; //Default FTP port is always 21 
const int BUFF_SIZE = 10000; //Default very large buffer size
const int S_BUFF_SIZE = 256; //Default smaller buffer size for things like user input
const int READY_FOR_NEW_USER = 220;
const int USER_LOGGED_IN = 230; //
const int SYNTAX_ERROR = 500; //Bad syntax
const int USER_OK_ENTER_PASSWORD = 331;	//Username ok, need password next
const int SYST_RCVD	= 215; //System info received
const int SRVC_CLOSING = 221; //Connection closed.
const int ACTION_OK = 250; //Whatever it was, it worked.
const int ACTION_FAILED = 550; //Whatever it was, it did not work
const int BAD_PASS = 501; //Bad password

char *buff;
bool wasQuitCalled = false;


#endif