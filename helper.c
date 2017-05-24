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
