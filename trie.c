#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct trie_node 
{
	int value;
	struct trie_node *child[27];
}my_trie_node;

//typedef trie_node my_trie_node;


typedef struct trie 
{
	my_trie_node *root;
	int count;
}my_trie;

//typedef trie my_trie;


my_trie_node* getnode()
{
	int i;
	my_trie_node *node=NULL;

	node=(my_trie_node *)malloc(sizeof(my_trie_node));

	if(node)
	{
		node->value=0;

		for(i=0;i<=26;i++)
			{
				node->child[i]=NULL;
			}
	}

	return node;
}

void initialize(my_trie *ptrie)
{
	ptrie->root=getnode();
	ptrie->count=0;
}

void insert(my_trie *ptrie,char key[])
{
	int level,len,index;
	len=strlen(key);
	my_trie_node *pcrawl;
	ptrie->count++;

	pcrawl=ptrie->root;

	for(level=0;level<len;level++)
	{
		index=key[level]-96;

		if(pcrawl->child[index]==NULL)
		{
			pcrawl->child[index]=getnode();
		}

		pcrawl=pcrawl->child[index];
	}

	pcrawl->value=ptrie->count;
}

int search(my_trie *ptrie,char key[])
{
	int level,len,index;
	len=strlen(key);
	my_trie_node *pcrawl;
	pcrawl=ptrie->root;

	for(level=0;level<len;level++)
		{
			index=key[level]-96;

			if(pcrawl->child[index]==NULL)
			{
				return 0;
			}

			pcrawl=pcrawl->child[index];
		}

	if(pcrawl->value > 0)	return 1;
	else	return 0;
}

int leafnode(my_trie_node *pnode)
{
	if(pnode->value!=0)	return 1;
	else
		return 0;
}
int freenode(my_trie_node *pnode)
{
	int i;
	for(i=0;i<=26;i++)
	{
		if(pnode->child[i]!=NULL)
		{
			return 0;
		}
	}

	return 1;
}

int deletetrie(my_trie_node *pnode,char key[],int level,int len)
{
	int index,condition;
	if(pnode)
	{
		if(level==len)
		{
			    index=key[level]-96;
				//printf("%c : uppr :\n",index+96);
				//printf("%d value: \n",pnode->value);
			
			if(pnode->value!=0)
			{
				pnode->value=0;
				//index=key[level]-96;
				//printf("%c : k :\n",index+96);
				if(freenode(pnode))
				{
					
					return 1;
				}
				return 0;
			}

		}
		else
		{
			index=key[level]-96;
			//printf("%c\n",index+96);
			condition=deletetrie(pnode->child[index],key,level+1,len);
			
			if(condition==1)
			{
				//printf("%c : here\n",index+96);
				free(pnode->child[index]);
				pnode->child[index]=NULL;
				return (leafnode(pnode)==0 && freenode(pnode)==1);

			}
		}
	}

	return 0;
}

void deletekey(my_trie *ptrie,char key[])
{
	int len=strlen(key),check;

	if(len > 0)
	{
		deletetrie(ptrie->root,key,0,len);
	}
	else
	{
		printf("empty key\n");
	}
}
int main()
{
	int i,check;
	char key[][8]={"the", "apple", "there", "answer", "any", "vivek","hello","vivekjo"};
	char  output[][32] = {"Not present in trie", "Present in trie"};
	my_trie mytrie;
	initialize(&mytrie);

	for(i=0;i<8;i++)
		{
			insert(&mytrie,key[i]);
		}

	 printf ("%s ­­­ %s\n", "th", output[search(&mytrie, "th")] );
     printf ("%s ­­­ %s\n", "these", output[search(&mytrie, "these")] );
     printf ("%s ­­­ %s\n", "vivek", output[search(&mytrie, "vivek")] );
     printf ("%s ­­­ %s\n", "hello", output[search(&mytrie, "hello")] );
     printf ("%s ­­­ %s\n", "there", output[search(&mytrie, "there")] );
     printf ("%s ­­­ %s\n", "yes", output[search(&mytrie, "yes")] );


     deletekey(&mytrie,"vivek");

     printf ("%s ­­­ %s\n", "vivek", output[search(&mytrie, "vivek")] );
     printf ("%s ­­­ %s\n", "vivekjo", output[search(&mytrie, "vivekjo")] );
     printf ("%s ­­­ %s\n", "vivek", output[search(&mytrie, "vivek")] );

     return 0;
}