
// Binary search (divide and conqer ) TC--> O(logn) 

int binarysearch(int a[],int l,int r,int val)
{
	if(l <= r)
	{
		int mid=(l+r)/2;
	
		if(a[mid]==val)	return mid;
	
		else if(a[mid] > val) return binarysearch(a,0,mid-1,val);
	
		else if(a[mid] < val) return binarysearch(a,mid+1,r,val);

	}
		return -1;


}


/*

#include<iostream>
using namespace std;

int main()
{
	int n,arr[100];
	
	cin>>n;

	for(int i=0;i<n;i++)	cin>>arr[i];
	
	int value;

	cin>>value;
	int pos=binarysearch(arr,0,n-1,value);
		
	if(pos==-1)	cout<<"\n not found.. ";
	
	else cout<<"\n found at: "<<pos;

	return 0;
}

*/
