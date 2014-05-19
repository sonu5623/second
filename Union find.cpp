#include <iostream>
#include <memory.h>
#include<stdio.h>
#define inchar getchar_unlocked

using namespace std;

int id[105],size[105];

inline int inp() {
      int n=0, ch;
      while((ch = inchar()) < '0');
      n=(ch-'0');
      while((ch=inchar())>='0') n=(n<<3)+(n<<1)+(ch-'0');
      return n;
}

void init()
{
int i;
memset(size,1,sizeof(int)*105);
 for(i = 0;i<105;i++)
  {
  
   id[i] = i;
  }

}


int root(int i)
{
  while(id[i] != i)
   {
     id[i] = id[id[i]];
     i = id[i];
   
   }
   return i;


}

int find(int p, int q)
{
 return root(p) == root(q);
}


void unionn(int p,int q)
{
 int i = root(p);
 int j = root(q);
 if(size[i] < size[j])
   {
     id[i] = j;
     size[j] += size[i];
   }
   
   else
   {
     id[j] = i;
     size[i] += size[j];
   }
   

}

int main() {
	// your code goes here
	int a,b,t,q,n,m,i;
	scanf("%d",&t);
	while(t--)
	{
	init();
	n = inp();
	m = inp();
	for(i = 1;i<=m;i++)
	{
	 unionn(inp(),inp());
	}
	q = inp();
	for(i = 1;i<=q;i++)
	{
	 if(find(inp(),inp()))
	  printf("YO\n");
	  else
	  printf("NO\n");
	}
	
	}
	
	
	return 0;
}