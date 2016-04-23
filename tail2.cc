#include<stdio.h>
#include<string.h>
#include <iostream>
using std::cout;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::getline;


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
   string line, buffer[NoL];
   size_t size = sizeof buffer / sizeof *buffer;
   size_t i = 0;

   while(getline(file, line))
   {
      buffer[i] = line;
      if( ++i >= size )
      {
         i = 0;
      }
   }

   for(size_t j = 0; j < size; ++j)
   {
      cout << buffer[i] << "\n";
      if(++i >= size)
      {
         i = 0;
      }
   }
   return;
}

void getlineStdin(const int NoL)
{
   string line, buffer[NoL];
   size_t size = sizeof buffer / sizeof *buffer;
   size_t i = 0;

   while(getline(std::cin, line))
   {
      buffer[i] = line;
      if( ++i >= size )
      {
         i = 0;
      }
   }

	cout << "\n";

   for(size_t j = 0; j < size; ++j)
   {
      cout << buffer[i] << "\n";
      if(++i >= size)
      {
         i = 0;
      }
   }
   return;
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

