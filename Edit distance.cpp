#include <iostream>
#include <stdio.h>
using namespace std;
int t,n,m,a[105],b[105],g,p,s,ans,i,j,tempmin,dist[105][105];

void editdistance()
{
  for(i = 0;i<=m;i++)
   dist[i][0] = i;
  for(j = 0;j<=n;j++)
    dist[0][j] = j;
  for(i = 1;i<=m;i++)
  {
     for(j = 1;j<=n;j++)
      {
        
        tempmin = dist[i-1][j]<dist[i][j-1]?dist[i-1][j]+1:dist[i][j-1]+1;
        if(a[i] != b[j])
        {
          dist[i][j] = tempmin<dist[i-1][j-1]+1?tempmin:dist[i-1][j-1]+1;
          
        
        }
        else
        {
        dist[i][j] = tempmin<dist[i-1][j-1]?tempmin:dist[i-1][j-1];
          
        }
      
      }
  }
    
    
}

int main() {
	// your code goes here
	
	scanf("%d",&t);
	while(t--)
	{
	  	scanf("%d",&m);
	  	for(i = 1;i<=m;i++)
	  	  	scanf("%d",&a[i]);
	  	scanf("%d",&n);
	  	for(i = 1;i<=n;i++)
	  	  	scanf("%d",&b[i]);
	  	editdistance();
	  	printf("%d\n",dist[m][n]);
	}  	  	
	return 0;
}