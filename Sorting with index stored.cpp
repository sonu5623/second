#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
int p,val,ko,a[1000],ind[1000],fin[1000],i,j,size=0,n,kr=0;
 #define inchar getchar_unlocked
 
 
inline int inp() {
      int n=0, ch;
      while((ch = inchar()) < '0');
      n=(ch-'0');
      while((ch=inchar())>='0') n=(n<<3)+(n<<1)+(ch-'0');
      return n;
}


inline void swap(int d , int k)
{
 int temp;
 temp = a[d];
 a[d] = a[k];
 a[k] = temp;
 
 
}
 
 inline void swaps(int d , int k)
{
 int temp;
 temp = ind[d];
 ind[d] = ind[k];
 ind[k] = temp;
 
 
}
 
inline int extractmin()
{
  int in,l,r,m;
 int ret = a[1];
 a[1] = a[size];
 kr++;
 fin[kr] = ind[1];
 ind[1] = ind[size];
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
       swaps(in,m);  
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
    swaps(i,p);
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
 	 ind[j] = j;
 	}
 	for(j=1;j<=n;j++)
 	{
 val = inp();
 	insert(val);
 	}
   for(j = 1;j<=n;j++)
   {
   printf("%d ",extractmin());
 	 
 	} 
 	cout<<"\n";
 	for(j = 1;j<=n;j++)
   {
   printf("%d ",fin[j]);
 	 
 	} 
	return 0;
}
