#include <iostream>
#include <memory.h>
using namespace std;

#define MAX_VERTEX 500
#define max_e 500
#define max_v 500
int e[max_e][2],pos,when[MAX_VERTEX],count=0,er[max_e][2],i,u,v,le[max_v],ler[max_v];
int visited[MAX_VERTEX];



void takeinput(int m)
{
    int u,v;
	i=1;
	
	memset(le,-1,sizeof(int)*max_v);
	memset(ler,-1,sizeof(int)*max_v);
	for(i=1;i<=m;i++)
	{
    scanf("%d %d",&u,&v);
	e[i][0] = v;
	e[i][1] = le[u];
	le[u] = i;
     
	er[i][0] = u;
	er[i][1] = ler[v];
	ler[v] = i;
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
  ++count;
  when[count] = v;
  }


void dfsreverse(int v)
{
 int u,id;
 visited[v] = 1;
 cout<<v<<'\t';
   id = ler[v];
while(id!=-1)
{
u = er[id][0];
if(visited[u]==0)
      dfsreverse(u);
id = er[id][1];
}
  
  }


void kosaraju(int n)
 {
  int i;
  memset(visited,0,sizeof(int)*max_v);
  for(i=1;i<=n;i++)
   {
    if(visited[i] == 0)
     {
       dfs(i);
     }
   }
   memset(visited,0,sizeof(int)*max_v);
   for(i=n;i>=1;i--)
   {
    pos = when[i];
    if(visited[pos] == 0)
    {
    dfsreverse(pos);
    cout<<'\n';
     }
   }
 }
 
 
int main() {
	// your code goes here
	int m,n,i;
	cin>>n;
	cin>>m;
	takeinput(m);
	kosaraju(n);
    //for(i=1;i<=n;i++)
     //cout<<when[i]<<'\t';
    
	return 0;
}

/*

 sample input
8 14
1 2
5 1
2 5
5 6
2 6
2 3
6 7
7 6
3 7
3 4
4 3
8 7
4 8
8 4

sample input
5 5
2 1
1 3
3 2
1 4
4 5

sample input
12 20
1 2
2 4
2 5
2 3
3 6
4 5
4 7
5 2
5 6
5 7
6 3
6 8
7 8
7 10
8 7
9 7
10 9
10 11
11 12
12 10
*/