#include<time.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long long int num=0;
	clock_t begin,end;
    double time_spent;

    begin=clock();
	for(long long int i=0;i<=100000000;i++)
	{
		num=num+1;
		//cout<<"hi";
	}
	printf("%lld\n",num);
	end=clock();
	time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
	cout<<"time: "<<time_spent;

	return 0;
}

/*

vivek@poppy:~/mycoding/algorithm$ ./a.out
100000001
time: 0.332287

*/


   


    
    