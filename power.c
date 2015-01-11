#include<stdio.h>
#define MOD 10

long long int fast_exp(long long int base,long long int exp) {
    long long int res=1;
    while(exp>0) {
       if(exp%2==1) 
       {
       		res=(res*base)%MOD;
       }
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

int main()
{
	long long int a,b,res;
	a=2;
	b=4;
	res=fast_exp(a,b);
	printf("%lld\n",res);
	return 0;
}