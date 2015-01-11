#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
 
long long segtree[3000100]={0},n,c;
 
inline void scan(long long *a) {
	register char c=0;
	while (c < 33)
		c = getchar_unlocked();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = getchar_unlocked();
	}
}
 
long long getMid(long long s,long long e)
{
	return (s+e)/2;
}
 
 
void updateUtil(long long ss, long long se, long long qs, long long qe, long long index,long long val)
{
    long long mid;
	if(qs>se||qe<ss)	return ;
 
	if(qs<=ss && qe>=se)
	{
		segtree[index]+=val;
		return ;
	}
 
	 mid=getMid(ss,se);
 
	updateUtil(ss,mid,qs,qe,2*index+1,val);
	updateUtil(mid+1,se,qs,qe,2*index+2,val);
}
 
 
void update()
{
	long long u,v,k;
//	scanf("%lld%lld%lld",&u,&v,&k);
 
	scan(&u); scan(&v); scan(&k);
	if(k==0) return;
 
	updateUtil(0,n-1,u-1,v-1,0,k);
}
 
long long getSumUtil(long long ss, long long se, long long index, long long p)
{
long long mid;
 
	if(ss==se )
	{
		return segtree[index];
	}
 
	mid=getMid(ss,se);
 
if(p<=mid)
	return segtree[index]+getSumUtil(ss,mid,2*index+1,p);
 
else
	return segtree[index]+getSumUtil(mid+1,se,2*index+2,p);
}
 
 
void query()
{
	long long p;
	//scanf("%lld",&p);
	scan(&p);
	printf("%lld\n",getSumUtil(0,n-1,0,p-1)+c);
}
 
 
int main()
{
	long long m,u,v,p;
	char ch;
//	scanf("%lld%lld%lld",&n,&m,&c);
//	updateUtil(0,n-1,0,n-1,0,c);
	scan(&n);
	scan(&m);
	scan(&c);
	while(m--)
	{
		ch=getchar();
		while(!(ch=='Q'||ch=='S'))
			ch=getchar();
//		printf("%c",ch);
 
		if(ch=='S')	update();
 
		if(ch=='Q')	query();
 
	}
 
	return 0;
}   