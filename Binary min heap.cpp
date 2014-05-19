// Binary min heap array implementation
#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
int p,val,ko,a[1000],i,j,size=0,n;

inline void swap(int d , int k)
{
 int temp;
 temp = a[d];
 a[d] = a[k];
 a[k] = temp;
 

}



inline int extractmin()
{
  int in,l,r,m;
 int ret = a[1];
 a[1] = a[size];
 a[size] = -1;
 size--;
 
 in = 1;
 l=2;
 r = 3;
 while(l<=size)
 {
  if( a[l]<a[r] ||a[r] ==-1  )
   m = l;
   else 
   m = r;
   if(a[in]>a[m])
     { 
        swap(in,m);
      in = m;
       l = 2*in;
       r = l+1;
       
     }
     else
       break;
 }
 
 return ret;
}

inline void insert(int val)
{
 size++;
 a[size] = val;
 
 i = size;
 p=i/2;
 while(p>0 && a[p]>a[i])
  {
    swap(i,p);
    i=p;
    p=p/2;
  
  }
}
int main() {
	// your code goes here
	memset(a,-1,1000*sizeof(int));
//cout<<a[1];
 	scanf("%d",&n);
 	for(j=1;j<=n;j++)
 	{
 	scanf("%d",&val);
 	insert(val);
 	}
 	for(i=1;i<16;i++)
 	 cout<<i<<" "<<a[i]<<'\n';
 	 for(j=1;j<=15;j++)
 	 cout<<extractmin()<<'\t';
 	
 	 
 	 
	return 0;
}
