

void mergeit(int arr[],int m,int k,int n)
{
	int c[101],pos=0,i=m,j=k+1;

	while(i<=k && j<=n)
	{
		if(arr[i] <  arr[j])
		{
			c[pos]=arr[i];
			pos++;
			i++;
		}
		else
		{
			c[pos]=arr[j];
			pos++;
			j++;
		}
	}

	while(i<=k)
	{
		c[pos]=arr[i];
		pos++;
		i++;
	}

	while(j<=n)
	{
		c[pos]=arr[j];
		pos++;
		j++;
	}

	for(i=m,j=0;i<=n;i++,j++)
	{
		arr[i]=c[j];
	}
}


void mergesort(int arr[],int m,int n)
{
	if( m < n)
	{
		int k=(m+n)/2;
		mergesort(arr,m,k);
		mergesort(arr,k+1,n);
		mergeit(arr,m,k,n);
	}
}

/*
#include<iostream>
using namespace std;

int main()
{
	int n,arr[101],i;
	
	cout<<"\n enter n: ";
	cin>>n;
	
	for(i=0;i<n;i++)	cin>>arr[i];
	
	mergesort(arr,0,n-1);
	
	for(i=0;i<n;i++)	
	{
		cout<<"  "<<arr[i];
	}
	
	cout<<"\n";
	
	return 0;
}
*/
