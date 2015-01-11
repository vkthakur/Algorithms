int prime[100001]={0};

void calculate_prime()
{
	int i,j;
	prime[1]=1;
	for(i=2;i<=sqrt(100000);i++)
	{
		for(j=i+1;j<=100000;j++)
		{
			if(prime[j]!=1)
			{
				if(j%i==0)	prime[j]=1;
			}
		}
	}

}

// 1 for not prime and 0 for prime.