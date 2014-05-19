

#include <iostream>
#include <memory.h>
using namespace std;
#define MAX_VERTEX 100010
#define max_e 100500
#define max_v 100500
int e[max_e][2],i,u,v,le[max_v],fin=0;
int count=0,discovered[max_v],finish[max_v],visited[MAX_VERTEX],colour[MAX_VERTEX];

void takeinput(int m)
{
	
	
	memset(le,-1,sizeof(int)*max_v);
	//scanf("%d %d",&u,&v);
	for(i=1;i<=m;i++)
	{
    scanf("%d %d",&u,&v);
	
	e[i][0] = v;
	e[i][1] = le[u];
	le[u] = i;
    
	}
}

void dfs(int v)
{
 int u,id;
  visited[v] = 1;
  discovered[v] = ++count;
  id = le[v];
  while(id!=-1)
  {
   u = e[id][0];
   if(visited[u]==0)
      dfs(u);
   id = e[id][1];
  }
  fin++;
  finish[fin] = v;
  
}

 
 
void topological(int num)
{
 int i;
fin = 0;
 memset(visited,0,sizeof(int)*max_v);
 for(i=1;i<=num;i++)
 {
  if(visited[i] == 0)
  {
    dfs(i);
    
  }
 }
 for(i=num;i>=1;i--)
  cout<<finish[i]<<'\t';
}


int main() {
	// your code goes here
	int n,m;
	scanf("%d %d",&n,&m);
	takeinput(m);
	topological(n);
	
	
	

	return 0;
} 


/*
sample input
8 9
6 2
1 2
1 4
3 4
3 7
2 5
2 8
2 7
4 8

*/