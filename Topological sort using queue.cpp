#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX_VERTEX 100010
#define max_e 100500
#define max_v 100500
int e[max_e][2],i,u,v,le[max_v],fin=0,result[MAX_VERTEX];
int count=0,discovered[max_v],finish[max_v],visited[MAX_VERTEX],indegree[MAX_VERTEX];
queue<int> q;
void takeinput(int m)
{
	
	memset(indegree,0,sizeof(int)*MAX_VERTEX);
	memset(le,-1,sizeof(int)*max_v);
	
	for(i=1;i<=m;i++)
	{
    scanf("%d %d",&u,&v);
	
	e[i][0] = v;
	e[i][1] = le[u];
	le[u] = i;
	indegree[v]++;
    
	}
}

void topological(int n)
{
int i,front,id,u,rin=0;
 for(i=1;i<=n;i++)
  {
    if(indegree[i] == 0)
      q.push(i);
  }
  while(!q.empty())
  {
     front = q.front();
     rin++;
     result[rin] = front;
     //cout<<front<<'\t';
     q.pop();
     id = le[front];
     while(id!=-1)
      {
        u = e[id][0];
        indegree[u]--;
        if(indegree[u] == 0)
          q.push(u);
        id = e[id][1];
      }

  }
  if(rin !=n)
   cout<<"Cycle exists";
   else
    {
     for(i=1;i<=n;i++)
       cout<<result[i]<<'\t';
    }
}
 


int main() {
	// your code goes here
	int n,m;
	scanf("%d %d",&n,&m);
	takeinput(m);
	//for(int i=1;i<=n;i++)
	 //cout<<indegree[i]<<'\t';
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