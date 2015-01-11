#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n,arr[1001][1001];
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	if(n==2)
	{
		if(arr[1][2]%2==0) 
		{
			int chk;
			chk=arr[1][2]/2;
			printf("%d %d\n",chk,chk);
		}
		else
		{
			int chk;
			chk=int(arr[1][2]/2);
			printf("%d %d\n",chk,chk+1);
		}
	}
	else
	{
		int a;
		a=(arr[1][2]+arr[1][3]-arr[2][3])/2;

		for(i=1;i<=n;i++)
		{
			if(i==1)
			{
				printf("%d ",a);
			}
			else
			{
				printf("%d ",arr[1][i]-a);
			}
		}
	}

	return 0;

}