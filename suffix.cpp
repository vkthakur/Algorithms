#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
		string str_suffix;
		int len_suffix,i,res=0;
		string suffix_arr[2000];

		cin>>str_suffix;
		len_suffix=str_suffix.size();

		for(i=0;i<len_suffix;i++)
		{
			suffix_arr[i]=str_suffix.substr(i,len_suffix);
		}


		cout<<"Before sorting: "<<endl;
		cout<<"\n";

		for(i=0;i<len_suffix;i++)
		{
			cout<<suffix_arr[i]<<endl;
		}


		sort(suffix_arr,suffix_arr+len_suffix);

		cout<<"\n";
		cout<<"After lexicographically sorting: "<<endl;
		cout<<"\n";

		for(i=0;i<len_suffix;i++)
		{
			cout<<suffix_arr[i]<<endl;
		}
		cout<<"\n";

	return 0;
}