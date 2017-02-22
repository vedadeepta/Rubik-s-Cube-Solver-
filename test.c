#include <stdio.h>
#include <time.h> 
int main () 
{
	int i=0;
	clock_t tic,toc;
	tic=clock();
	printf("start");
	printf("hello world");
	printf("this");
	printf("that");
	
	toc=clock();
    printf("time to run = %f\n",(double)((toc-tic)/CLOCKS_PER_SEC ));
   	return 0;
}