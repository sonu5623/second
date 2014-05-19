#include <iostream>
#include <string.h>
using namespace std;

char t[100000],p[1000],prefix[1000];

void computeprefix()
{
  int m,k,q;
  m = strlen(p);
  prefix[0] = -1;
  k = -1;
  for(q=1;q<m;q++)
  {
      while(k>-1 && p[k+1]!= p[q])
       k = prefix[k];
      if(p[k+1]==p[q])
       k++;
      prefix[q] = k;
      
  }
  
}

void kmp()
{
 int n,m,q,i;
 n= strlen(t);
 m = strlen(p);
 computeprefix();
 
 
 q = -1;
 for(i=0;i<n;i++)
 {
   while(q>-1 && p[q+1]!=t[i])
    q= prefix[q];
    if(p[q+1] == t[i])
    q++;
    if(q == m-1)
    {
     printf("pattern occurs with shift %d\n",i-m+1);
     q = prefix[q];
    }
 }
}


int main() {
	// your code goes here
	scanf("%s",t);
	scanf("%s",p);
	
	kmp();
	return 0;
}
