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


int main(int argc,string argv[])
{
	if(argc!=2)
	{
		printf("Usage:fifteen d\n");
		return 1;
	}

	d=atoi(argv[1]);
	if(d<DIM_MIN||d>DIM_MAX)
	{
		printf("The board must be betwwen %iX%i and %iX%i,inclusive.\n",DIM_MIN,DIM_MIN,DIM_MAX,DIM_MAX);
		return 2;
	}

	FILE *file=fopen("log.txt","w");

	if(file==NULL)
	{
		return 3;
	}

	greet();
	init();

	while (true)
	{
		clear();
		draw();
		for(int i=0;i<d;i++)
		{
			for(int j=0;j<d;j++)
			{
				fprintf(file,"%i",board[i][j]);
				if(j<d-1)
				{
					fprintf(file,"|");
				}
			}
			fprintf(file,"\n");
		}
		fflush(file);

		if(won())
		{
			printf("ftw!\n");
			break;
		}

		printf("Tile to move:");
		int tile=get_int();

		if(tile==0)
			break;
		
		fprintf(file,"%i\n",tile);
		fflush(file);

		if(!move(tile))
		{
			printf("\nIllegal move.\n");
			usleep(500000);
		}
		usleep(500000);
	}
	fclose(file);
	return 0;
	
}

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

void draw(void)
{
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		{
			printf("%3d",board[i][j]);
		}
		printf("\n");
	}
}


bool move(int tile)
{
	int r=0,c=0;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		{
			if(board[i][j]==0)
			{
				r=i;
				c=j;
			}
		}

	}
	if(tile==board[r+1][c])
	{
		board[r][c]=tile;
		board[r+1][c]=0;
		return true;
	}
	else if(tile==board[r-1][c])
	{
		board[r][c]=tile;
		board[r-1][c]=0;
		return true;
	}
	else if(tile==board[r][c+1])
	{
		board[r][c]=tile;
		board[r][c+1]=0;
		return true;
	}
	else if(tile==board[r][c-1])
	{
		board[r][c]=tile;
		board[r][c-1]=0;
		return true;
	}
	else
		return false;

}




bool won(void)
{
	int p=1,t=0;
	for(int i=0;i<d;i++)
	{
		if(i!=(d-1))
		{
			for(int j=0;j<d;j++)
			{
				if(board[i][j]!=p)
				{
					t=1;
					break;
				}
				p++;
			}
		}
		else
		{
			for(int j=0;j<d-1;j++)
			{
				if(board[i][j]!=p)
				{
					t=1;
					break;
				}
				p++;
			}
		}
	}
	if(t)
		return false;
	else
		return true;
}

