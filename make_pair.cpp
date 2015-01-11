#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	int i,frst,scnd;

	vector<pair<int,int> >vct;
	
	for(i=0;i<5;i++)
	{
		cout<<"Enter value pair: ";
		cin>>frst>>scnd;
		vct.push_back(make_pair(frst,scnd));
	}

	cout<<"first: "<<endl;

	for(i=0;i<5;i++)
	{
		printf("%d : %d \n",vct[i].first,vct[i].second);
	}

	sort(vct.begin(),vct.begin()+5);

	cout<<"second: "<<endl;

	for(i=0;i<5;i++)
	{
		printf("%d : %d \n",vct[i].first,vct[i].second);
	}

	return 0;
}

/*

vivek@poppy:~/mycoding/algorithm$ g++ make_pair.cpp 
vivek@poppy:~/mycoding/algorithm$ ./a.out
Enter value pair: 2 4
Enter value pair: 1 5
Enter value pair: 3 7
Enter value pair: 8 9
Enter value pair: 6 7
first: 
2 : 4 
1 : 5 
3 : 7 
8 : 9 
6 : 7 
second: 
1 : 5 
2 : 4 
3 : 7 
6 : 7 
8 : 9 



*/