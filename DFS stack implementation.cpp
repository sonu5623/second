#include <iostream>
#include <memory.h>
using namespace std;
#define MAX_STACK 1000
#define MAX_VERTEX 500
#define max_e 500
#define max_v 500
int e[max_e][2],i,u,v,le[max_v];
int visited[MAX_VERTEX],stack[MAX_STACK],top;


/*
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
*/
void takeinput_undirected()
{
	i=1;
	memset(le,-1,sizeof(int)*max_v);
	scanf("%d %d",&u,&v);
	for(i=1;u!=0;i++)
	{
	e[i][0] = v;
	e[i][1] = le[u];
	le[u] = i;
     i++;
	e[i][0] = u;
	e[i][1] = le[v];
	le[v] = i;
	scanf("%d %d",&u,&v);
	}
}


void takeinput()
{
	i=1;
	memset(le,-1,sizeof(int)*max_v);
	scanf("%d %d",&u,&v);
	for(i=1;u!=0;i++)
	{
	e[i][0] = v;
	e[i][1] = le[u];
	le[u] = i;
	scanf("%d %d",&u,&v);
	}
}

void createstack()
{
 top = 0;
}

void push(int v)
{
 stack[top] = v;
 top++;

}

int pop()
{
top--;
return stack[top];

}

bool isempty()
{
return top==0?true:false;
}





void dfs(int v)
{
 int u,id;
 createstack();
 memset(visited,0,sizeof(int)*MAX_VERTEX);
 push(v);
 while(!isempty())
 {
  v = pop();
  if(visited[v]==0)
  {
   visited[v] = 1;
   cout<<v<<'\t';
   id = le[v];
while(id!=-1)
{
u = e[id][0];
if(visited[u]==0)
      push(u);
id = e[id][1];
}
  
  }
 }
 

}


int main() {
	// your code goes here
	takeinput();
	dfs(7);
	return 0;
}