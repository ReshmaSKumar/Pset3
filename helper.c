#include<cs50.h>
#include "helpers.h"

bool search(int value,int values[],int n)
{
	int upper=0;
	int lower=n;
	while(upper<=lower)
	{
		int mid=(upper+lower)/2;
		if(values[mid]==value)
		{
			return true;
			break;
		}
		else
			if(value>values[mid])
			{
				upper=mid+1;
			}
			else
				lower=mid-1;
	}
	return false;

}

void sort(int values[],int n)
{
	int i=0;
	int p=0;
	int temp=0;
	while(i<=n)
	{
		int min=values[i];
		for(int j=i;j<=n;j++)
		{
			if(values[j]<=min)
			{
				min=values[j];
				p=j;
			}
		}
		temp=values[i];
		values[i]=min;
		values[p]=temp;
		i++;
	}
	return;
}
