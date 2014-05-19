#include <iostream>
#include<queue>
using namespace std;

struct vertex{
int val;
int dist;
char color;
};

int main() {
	// your code goes here
	struct vertex a[220],u;
	int t,n,i,j,q,s,d,p,shortest[220][220];
	char dummy;
	char map[220][220];
	scanf("%d",&t);
	while(t--)
	{
	   scanf("%d",&n);
	   scanf("%c",&dummy);
	   for(i = 1;i<=n;i++)
	   {
	     for(j = 1; j<=n;j++)
	     
	       scanf("%c",&map[i][j]);
	     scanf("%c",&dummy);
	}
	
	for(p=1;p<=n;p++)
	{
	 for(i=1;i<=n;i++)
	      {
	        a[i].val = i;
	        a[i].dist = 100000;
	        a[i].color = 'w';
	      }
	      a[p].dist = 0;
	      a[p].color = 'g';
	     std::queue<struct vertex> q;
	     q.push(a[p]);
	     while(!q.empty())
	     {
	       u = q.front();
	       q.pop();
	       for(j=1;j<=n;j++)
	       {
	      

	         if(map[u.val][j] == 'Y')
	         {
	         	       
	            if(a[j].color == 'w')
	            {
	               a[j].color = 'g';
	               a[j].dist = u.dist+1;
	               q.push(a[j]);
	               
	            }
	         
	         }
	       }
	     
	     }
	     
	     for(i = 1;i<=n;i++)
	        shortest[p][i] = a[i].dist;
	}
	
	

	  scanf("%d",&q);
	  
	  while(q--)
	  {
	     scanf("%d %d",&s,&d);
	     s++;d++;
	    printf("%d\n",shortest[s][d]);
	     
	     
	     
	  }
	
	
	}

	return 0;
}
