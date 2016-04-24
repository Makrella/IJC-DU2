#include<iostream>
#include<queue>
#include<string>
#include<fstream>

#include<stdio.h>
#include<string.h>

using namespace std;


void errMsg()
{
	fprintf(stderr,"Dominik Drdak\nxdrdak01\nIJC - DU2\nBUT FIT\n\
***********************************************\n\
WRONG INPUT\n\
Correct Input:\n\
./tail\n\
./tail 'filename'\n\
./tail -n 'number of desired last lines form stdin'\n\
./tail -n 'number of desired last lines form stdin' 'filename'\n");
}

void getlineFile(const int NoL, string filename)
{
	ifstream file(filename);
	string line;
	queue<string> buffer;

	for(int i = 0; i < NoL && getline(file, line); i++)
	{
		buffer.push(line);
	}

	while(getline(file, line))
	{
		buffer.pop();
		buffer.push(line);
	}


	for(int k = 0;k < NoL; k++)
	{
		cout << buffer.front() << endl;
		buffer.pop();
		if(buffer.size() == 0)
		{
			return;
		}
	}
}


void getlineStdin(const int NoL)
{
	string line;
	queue<string> buffer;

	for(int i = 0; i < NoL && getline(std::cin, line); i++)
	{
		buffer.push(line);
	}

	while(getline(std::cin, line))
	{
		buffer.pop();
		buffer.push(line);
	}

	cout << "\n";

	for(int k = 0;k < NoL; k++)
	{
		cout << buffer.front() << endl;
		buffer.pop();
		if(buffer.size() == 0)
		{
			return;
		}
	}
}

int main (int argc, char *argv[])
{
	switch(argc)
	{
		case(1)		:
			getlineStdin(10);
			break;
		case(2)		:
			
			getlineFile(10,argv[1]);
			break;
			
			
		case(3)		:
			if(!strcmp(argv[1],"-n"))
			{
				char *ptr;
				getlineStdin(strtol(argv[2],&ptr,10));
			}
			else
			{
				errMsg();
			}
			break;
		case(4)		:
			if(!strcmp(argv[1],"-n"))
			{
				char *ptr;
				getlineFile(strtol(argv[2],&ptr,10),argv[3]);
			}
			else
			{
				errMsg();
			}
			break;
		default		:
		break;
			errMsg();	
	}
	return 1;
}

