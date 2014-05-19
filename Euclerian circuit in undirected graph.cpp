// finding euclerian circuit in undirected graph

#include <iostream>
#include <memory.h>
using namespace std;
#define MAX_VERTEX 100010
#define max_e 100500
#define max_v 100500
int e[max_e][2],i,u,v,le[max_v];
int visited[MAX_VERTEX],degree[max_v];

void takeinput_undirected(int m)
{
    int u,v;
	i=1;
	m=m*2;
	memset(le,-1,sizeof(int)*max_v);
   	memset(degree,0,sizeof(int)*max_v);
	for(i=1;i<=m;i++)
	{
    scanf("%d %d",&u,&v);


	//u++;  // if vertex no starts from 0
	//v++;
	degree[u]++;
	degree[v]++;
	e[i][0] = v;
	e[i][1] = le[u];
	le[u] = i;
     i++;
	e[i][0] = u;
	e[i][1] = le[v];
	le[v] = i;
	}
}

void dfs(int v)
{
 int u,id;
  visited[v] = 1;
 
  id = le[v];
  while(id!=-1)
  {
   u = e[id][0];
   if(visited[u]==0)
      dfs(u);
   id = e[id][1];
  }
  
}

 
void eucleriancircuit(int n)
{

 for(i=1;i<=n;i++)
 {
  if(degree[i] != 0)
    {
      dfs(i);
      break;  
    }
 }
 int ans = 1;
 
     
	 for(i=1;i<=n;i++)
	 {
	   if(degree[i]!=0 && visited[i] == 0)
	   {
	     ans = 0;
	     break;
	   }
	   if(degree[i]%2 != 0)
	   {
	     ans = 0;
	     break;
	   }
	}
	
 
 if(ans)
  cout<<"Euclerian circuit exists\n";
  else
  cout<<"Euclerian circuit does not exists\n";
   
}

int main() {
	// your code goes here
	int n,m;
	scanf("%d %d",&n,&m);
	takeinput_undirected(m);
	eucleriancircuit(n);
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