#define _XOPEN_SOURCE 500
#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define DIM_MIN 3
#define DIM_MAX 9

int board[DIM_MAX][DIM_MAX];

int d;

void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

void clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH",0,0);
}

void greet(void)
{
	clear();
	printf("WELCOME TO THE GAME OF FIFTEEN\n");
	usleep(2000000);
}

void init(void)
{
	int p=(d*d)-1;
	int temp=0;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		{
			board[i][j]=p;
			p--;
		}
	}
	if((d%2)==0)
	{
		temp=board[d-1][d-3];
		board[d-1][d-3]=board[d-1][d-2];
		board[d-1][d-2]=temp;
	}
}
