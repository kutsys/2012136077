#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()	{
	time_t rawtime;
	while(1)	{
		time(&rawtime);
		printf("localtime : %s\n", ctime(&rawtime));
		sleep(2);
	}
}
