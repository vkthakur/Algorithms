#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int lps[101];

void compute_lps(char pat[],int pat_len)
{
	int len=0,i=1;
	lps[0]=1;
	
	while(i < pat_len)
	{
		if(pat[i]==pat[len]){
			
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}

}


int kmp(char txt[],char pat[])
{
	int len_txt,len_pat;
	
	len_txt=strlen(txt);
	len_pat=strlen(pat);
	
	compute_lps(pat,len_pat);
	
	int j=0,i=0;
	
	while(i < len_txt)
	{
		
		if(pat[j]==txt[i])	{
		
			i++;
			j++;

			if(j==len_pat)	return i-j;		// we can display the index position by (i-j)

		}
				
		else if(pat[j]!=txt[i])	{
		
			if(j!=0)	j=lps[j-1];

			else	i++;
			
		}
	
	}
		
	return -1;


}


int main()
{
	char str1[200],str2[100];
	
	cout<<"\n Enter the text-string: ";
	gets(str1);
	cout<<"\n Enter the pattern-string: ";
	gets(str2);
	
	int check=kmp(str1,str2);
	
	if(check!=-1)	cout<<"\n pattern found in text at: "<<check;
	
	else if(check==-1) cout<<"\n pattern doesn't not found in text ";
	
	cout<<"\n";

	return 0;
	
}
