#include<iostream>
#define maxx 9999;
using namespace std;

int cost[101][101]={0},adjmatrix[101][101],n,stnode,i,j;

void calculatecost()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(adjmatrix[i][j]!=0)
			{
				cost[i][j]=adjmatrix[i][j];
			}
			else
			{
				cost[i][j]=maxx;
			}

		}
	}
}

void calculatedijsktra(int st)
{
	int visited[101]={0},distance[101],path[101];

	for(i=0;i<n;i++)
	{
		distance[i]=cost[st][i];
		visited[i]=0;
		path[i]=st;
	}

	visited[st]=1;
	distance[st]=0;

	int count=1;
	int nxtnode;

	while(count < n-1)
	{
		int mindisity=maxx;

		for(i=0;i<n;i++)
		{
			if(distance[i] < mindisity && visited[i]==0)
			{
				mindisity=distance[i];
				nxtnode=i;
			} 
		}
		visited[nxtnode]=1;

		for(i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				if(mindisity+cost[nxtnode][i] < distance[i])
				{
					distance[i]=mindisity+cost[nxtnode][i];
					path[i]=nxtnode;
				}
			}
		}
		count++;
	}

	for(i=0;i<n;i++)
	{
		if(i!=st)
		{
			cout<<"\n distance of node "<<i<<" = "<<distance[i];
			cout<<"\n path = "<<i;
			j=i;
			do
			{
				j=path[j];
				cout<<" <- "<<j;
			}while(j!=st);
		}
	}

}
int main()
{

	cout<<"\n enter count_nodes: ";
	cin>>n;

	cout<<"\n enter the distance between i and j node: ";

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>adjmatrix[i][j];
		}
	}

	calculatecost();

	cout<<"\n enter the starting node: ";
	cin>>stnode;

	calculatedijsktra(stnode);

	cout<<"\n";
	
	return 0;
}
