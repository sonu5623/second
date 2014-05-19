#include <iostream>
#include <memory.h>
using namespace std;
#define max_e 50
#define max_v 50
int e[max_e][2],i,u,v,le[max_v];

void print_neighbour(int v)
{
int u,id;
id = le[v];
while(id!=-1)
{
u = e[id][0];
cout<<u<<'\t';
id = e[id][1];
}
cout<<'\n';
}

int main() {
	// your code goes here
	// we believe that the input is the set of edges u v and the list is terminated by 0 0
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
	
	/*	for(i=1;i<6;i++)
	 {
	print_neighbour(i);
	}


	// The next lines are just for printing the structures created
	
	for(i=1;i<10;i++)
	 {
	  cout<<e[i][0]<<"   "<<e[i][1]<<'\n';
	  
	 }
	 cout<<"\nvertex\n";
	 	for(i=1;i<6;i++)
	 {
	  cout<<le[i]<<'\n';
	  
	 } 
	 */

//sample input    1 2 2 3 1 3 1 5 4 3 3 2 4 2 2 5 0 0
	return 0;
}
