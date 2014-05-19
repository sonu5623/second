// Complexity n*n


#include <iostream>
#include<string.h>
using namespace std;
char a[1010];int i,j,n,k,p,l,dp[1005][1005];

int main() {
	// your code goes here
	scanf("%s",a+1);
	n = strlen(a+1);
	for(i = 1;i<=n;i++)
	{
	 dp[i][i] = 0;
	 dp[i][i-1] = 0;
	}
	
	for(j = 2,k=1;j<=n;j++,k++)
	{
	 p = j;
	 l = n-k;
	 for(i = 1;i<=l;i++)
	 {
	  if(a[i] == a[p])
	   dp[i][p] = dp[i+1][p-1];
	 else
	 dp[i][p] = ((dp[i+1][p]<=dp[i][p-1])?dp[i+1][p]+1:dp[i][p-1]+1); 
	 
	 p++;
	 }
	
	}
	
	
	
	
	printf("%d\n",dp[1][n]);
	
	
	return 0;
}