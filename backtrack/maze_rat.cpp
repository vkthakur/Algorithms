#include<iostream>
#include<stdio.h>
using namespace std;
#define n 4

int isSafe(int maze[n][n],int x,int y)
{
	if(x>=0 && x<n && y>=0 && y <n && maze[x][y]==1)
	{
		return 1;
	}

	return 0;
}

int solveMazeutil(int maze[n][n],int x,int y,int sol[n][n])
{
	if(x==n-1 && y==n-1)	
	{
		sol[x][y]=1;
		return 1;
	}

	int k=isSafe(maze,x,y);
	if(k==1)
	{
		sol[x][y]=1;

		if(solveMazeutil(maze,x+1,y,sol)==1)	return 1;

		if(solveMazeutil(maze,x,y+1,sol)==1)	return 1;
		
		sol[x][y]=0;

		return 0;		
	}

	return 0;
}

void solveMaze(int maze[n][n])
{
	int sol[n][n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) {sol[i][j]=0;}
	}
	
	if(solveMazeutil(maze,0,0,sol)==0)
	{
		printf("Solution doesn't exist\n");
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) 
				{
					printf("%d ",sol[i][j]);
				}
			printf("\n");
		}
	}
}
int main()
{
	int maze[n][n]={
		{1,0,0,0},
		{1,1,0,1},
		{0,1,0,0},
		{1,1,1,1}
	};

	solveMaze(maze);
	return 0;
}

/*
vivek@poppy:~/mycoding/algorithm/backtrack$ g++ maze_rat.cpp 
vivek@poppy:~/mycoding/algorithm/backtrack$ ./a.out
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 
*/