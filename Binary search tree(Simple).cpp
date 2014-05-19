// Simple bst implementation

#include <iostream>
#include <stdio.h>
#include<memory.h>
using namespace std;
int a[1000],i,j,k;
void insert(int val,int pos)
{
if(a[pos] == -1)
 a[pos] = val;
 else if(val>=a[pos])
  insert(val,2*pos+1);
  else
  insert(val,2*pos);
}

int main() {
	// your code goes here
int val,n;
memset(a,-1,1000*sizeof(int));
//cout<<a[1];
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 	scanf("%d",&val);
 	insert(val,1);
 	}
 	for(i=1;i<23;i++)
 	 cout<<i<<" "<<a[i]<<'\n';
	return 0;
}