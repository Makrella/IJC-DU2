#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define DEFAULT_N_LINES 10
#define MAX_CHARS_LINE 510

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

void getlineStdin(const int NoL)
{
	char *line[NoL+1];
	int i,j,k,l;
	size_t n;


	for(i = 1, k = 0; i <= NoL+1 && (!feof(stdin)); i++)
	{
		n=0;
		getline(&line[i], &n, stdin);
		k++;
	}

	l=0;
	while(!feof(stdin))
	{
		bool freeFLAG = false;

		for(j = 0; j <= i && k+1 != j; j++)
		{

			if(freeFLAG == true && l != 0)
			{
				free(line[0]);
			}

			freeFLAG = false;

			if(j == 0 && freeFLAG == false)
			{
				freeFLAG = true;
				if(l == 1)
				{
					free(line[j]);
				}
			}
			line[j] = line[j+1];
		}

		l++;
		n = 0;
		getline(&line[i], &n, stdin);
		line[i-1] = line[i];
	}

	printf("\n");
	for(j = 1; j < k+1; j++)
	{
		printf("%s",line[j]);
	}
	
	for(j = 1; j < k+1; j++)
	{
		free(line[j]);
	}
}


void getlineFile(const int NoL, char filename[])
{
	char *line[NoL+1];
	int i,j,k,l;
	size_t n;
	FILE *file;
	file = fopen(filename, "r");
 
	if (file == NULL)
	{
		errMsg();
		return;
	}

	for(i = 1, k = 0; i <= NoL+1 && (!feof(file)); i++)
	{
		n=0;
		getline(&line[i], &n, file);
		k++;
	}

	l=0;
	while(!feof(file))
	{
		bool freeFLAG = false;

		for(j = 0; j <= i && k+1 != j; j++)
		{

			if(freeFLAG == true && l != 0)
			{
				free(line[0]);
			}

			freeFLAG = false;

			if(j == 0 && freeFLAG == false)
			{
				freeFLAG = true;
				if(l == 1)
				{
					free(line[j]);
				}
			}

			line[j] = line[j+1];
		}

		l++;
		n = 0;
		getline(&line[i], &n, file);
		line[i-1] = line[i];
	}

	for(j = 1; j < k+1; j++)
	{
		printf("%s",line[j]);
	}
	
	for(j = 1; j < k+1; j++)
	{
		free(line[j]);
	}
	fclose(file);
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

