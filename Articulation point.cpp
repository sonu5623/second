// program link   http://www.codechef.com/problems/KINGCON

#include <iostream>
#include <memory.h>
using namespace std;

#define MAX_VERTEX 10000
#define max_e 10000500
#define max_v 10000
int e[max_e][2],timed=0,i,v,le[max_v];
int visited[MAX_VERTEX],d[MAX_VERTEX],low[MAX_VERTEX],t,n,k,pred[MAX_VERTEX],num_arb=0;


void articulation(int v)
{
int id,u,num_child=0,ent=0;
 visited[v] = 1;
 d[v] = ++timed;
 low[v] = timed;
 id = le[v];
 while(id != -1)
 {
  u = e[id][0];
  
  if(visited[u] == 0)
    {
    
     pred[u] = v;
     articulation(u);
    
     if(pred[v] == 0)
      {
          num_child++;
         if(num_child == 2)
         {
         num_arb++;
         //cout<<"root "<<v<<'\n'; // v is the arbitration point
         }
      }
      else if(low[u] >= d[v])
      {
       ent++;
       if(ent == 1)
        {
         num_arb++;
         //cout<<"internal "<<v<<'\n'; // v is the arbitration point
        }
       }
      low[v]= low[v]<low[u]?low[v]:low[u];
    }
   else if(u!= pred[v])
    {
      
      low[v] = low[v]<d[u]?low[v]:d[u];
    }
  id = e[id][1];
 }
 
}



void takeinput_undirected(int m)
{
    int u,v;
	i=1;
	m=m*2;
	memset(le,-1,sizeof(int)*max_v);
	for(i=1;i<=m;i++)
	{
    scanf("%d %d",&u,&v);
	u++;
	v++;
	e[i][0] = v;
	e[i][1] = le[u];
	le[u] = i;
     i++;
	e[i][0] = u;
	e[i][1] = le[v];
	le[v] = i;
	}
}



int main() {
	// your code goes here
	int m;
	    scanf("%d",&t);
    while(t--)
    {
    num_arb = 0;
	memset(visited,0,sizeof(int)*max_v);
	memset(pred,0,sizeof(int)*max_v);
	    scanf("%d %d %d",&n,&m,&k);
	takeinput_undirected(m);
	articulation(1);
    printf("%d\n",num_arb*k);
	}
	return 0;
}

/* test cases
2
7 6 5
0 1
1 2
3 4
2 4
2 6
5 2
13 16 5
0 1
0 2
0 5
0 6
3 4
3 5
4 5
2 6
4 6
6 7
7 8
6 9
9 10
9 11
9 12
11 12

*/
