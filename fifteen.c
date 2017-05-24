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

