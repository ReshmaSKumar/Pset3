#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

const int MAX=65536;

int main(int argc,string argv[])
{
	if(arc!=2)
	{
		printf("Usage:./find needle\n");
		return -1;
	}
	
	int needle=atoi(argv[1]);
	int size;
	int haystack[MAX];
	for(size=0;size<MAX;size++)
	{
		printf("\nhaystack[%i]=",size);
		int straw=get_int();
		if(straw==INT_MAX)
			break;
		haystack[size]=straw;
	}
	printf("\n");
}
