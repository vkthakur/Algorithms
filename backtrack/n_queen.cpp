/*
http://www.facebook.com/l.php?u=http%3A%2F%2Fwww.math.utah.edu%2F~alfeld%2Fqueens%2Fqueens.html&h=gAQGoSvc-

*/

#include<iostream>
#include<stdio.h>
using namespace std;
#define n 4

int isSafe(int board[n][n],int row,int col)
{
	int i,j;

	for(i=0;i<col;i++)
	{
		if(board[row][i]==1)	return 0;
	}

	for(i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==1)	return 0;
	}

	for(i=row,j=col;j>=0 && i<n;i++,j--)
	{
		if(board[i][j]==1)	return 0;
	}

	return 1;
}

int solvenqutil(int board[n][n],int col)
{
	if(col==n)	return 1;

	for(int i=0;i<n;i++)
	{
		int k=isSafe(board,i,col);

		if(k==1)
		{
			board[i][col]=1;

			if(solvenqutil(board,col+1)==1)	return 1;

			board[i][col]=0;
		}
	}

	return 0;	
}


void solvenq()
{
	int board[n][n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j]=0;
		}
	}

	if(solvenqutil(board,0)==0)
	{
		printf("Solution doesn't exist\n");
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	solvenq();
	return 0;
}

/*

vivek@poppy:~/mycoding/algorithm/backtrack$ g++ n_queen.cpp
vivek@poppy:~/mycoding/algorithm/backtrack$ ./a.out
1 
vivek@poppy:~/mycoding/algorithm/backtrack$ g++ n_queen.cpp
vivek@poppy:~/mycoding/algorithm/backtrack$ ./a.out
Solution doesn't exist
0 0 
0 0 
vivek@poppy:~/mycoding/algorithm/backtrack$ g++ n_queen.cpp
vivek@poppy:~/mycoding/algorithm/backtrack$ ./a.out
Solution doesn't exist
0 0 0 
0 0 0 
0 0 0 
vivek@poppy:~/mycoding/algorithm/backtrack$ g++ n_queen.cpp
vivek@poppy:~/mycoding/algorithm/backtrack$ ./a.out
Solution doesn't exist
0 0 0 
0 0 0 
0 0 0 
vivek@poppy:~/mycoding/algorithm/backtrack$ g++ n_queen.cpp
vivek@poppy:~/mycoding/algorithm/backtrack$ ./a.out
0 0 1 0 
1 0 0 0 
0 0 0 1 
0 1 0 0 
vivek@poppy:~/mycoding/algorithm/backtrack$ g++ n_queen.cpp
vivek@poppy:~/mycoding/algorithm/backtrack$ ./a.out
1 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 1 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 0 0 1 0 0 
0 0 1 0 0 0 0 0 

*/