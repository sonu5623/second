// problem solotion 
// http://www.codechef.com/problems/HDELIVER

#include <iostream>
#include <memory.h>
using namespace std;
#define MAX_STACK 1000000
#define MAX_VERTEX 100010
#define max_e 100500
#define max_v 100500
int e[max_e][2],i,u,v,le[max_v];
int visited[MAX_VERTEX],stack[MAX_STACK],top,color[MAX_VERTEX];
 
void takeinput_undirected(int m)
{
	i=1;
	m=m*2;
	memset(le,-1,sizeof(int)*max_v);
	//scanf("%d %d",&u,&v);
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
	//scanf("%d %d",&u,&v);
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
 
 
 
 
 
void dfs(int v,int level)
{
 int u,id;
 createstack();
 push(v);
 while(!isempty())
 {
  v = pop();
  if(visited[v]==0)
  {
   visited[v] = 1;
   color[v] = level;
   //cout<<v<<'\t';
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
int isconnected(int a,int b)
{
 if(color[a]==color[b])
 return 1;
 else
 return 0;
}
 
void colorgraph(int num)
{
 int i,level=1;
 memset(color,-1,sizeof(int)*MAX_VERTEX);
 memset(visited,0,sizeof(int)*MAX_VERTEX);

 for(i=1;i<=num;i++)
 {
  if(color[i] == -1)
  {
    dfs(i,level);
    level++;
  }
 }
 
}
int main() {
	// your code goes here
	//takeinput_undirected();
	//takeinput();
	//dfs(2);
	int a,b,t,q,n,m;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d %d",&n,&m);
	takeinput_undirected(m);
	colorgraph(n);
	scanf("%d",&q);
	while(q--)
	{
	  scanf("%d %d",&a,&b);
	  if(isconnected(a+1,b+1) == 1)
	     printf("YO\n");
	  else
	  printf("NO\n");
	}
	
	}
	
	
//	colorgraph(8);
	//for(i=1;i<=8;i++)
	 // cout<<color[i]<<'\n';
	return 0;
} 