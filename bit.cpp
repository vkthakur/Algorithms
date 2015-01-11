#include<iostream>
#include<math.h>
using namespace std;

int tree[101]={0};

void create_bit_tree(int arr[],int tree[],int n)
{
	int r_pos,start_pos,i,j;

	for(i=1;i<=n;i++)
	{
		r_pos=log2(i & (-i));
		start_pos=i-pow(2,r_pos)+1;

		for(j=start_pos;j<=i;j++)
		{
			tree[i]=tree[i]+arr[j];
		}
	}

	for(i=1;i<=n;i++)
	{
		cout<<tree[i]<<" ";
		
	}
}

void read_bit_tree(int tree[],int n,int indx)
{
	int k,sum=0;
	while(indx >= 1)
	{
		sum=sum+tree[indx];
		indx=indx - (indx & (-indx));
	}

	cout<<"\nsum: "<<sum;
}

void update_bit_tree(int tree[],int n,int indx,int value)
{
	while(indx <= n)
	{
		tree[indx]=tree[indx] + value;

		indx=indx + (indx & (-indx));

	}

	int i;
	for(i=1;i<=n;i++)
	{
		cout<<tree[i]<<" ";
	}

}

int main()
{
	int n,arr[101],i;

	cout<<"\n enter n: ";
	cin>>n;

	for(i=1;i<=n;i++)	cin>>arr[i];

	create_bit_tree(arr,tree,n);
	
	int indx,value;
	indx=5;
	read_bit_tree(tree,n,indx);
	cout<<"\n";
	value=5;
	update_bit_tree(tree,n,indx,value);
	cout<<"\n";
	indx=5;
	read_bit_tree(tree,n,indx);
	return 0;	
}