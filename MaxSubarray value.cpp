#include <iostream>
using namespace std;


long long int n,a[100010],lt[100010],lm[100010],rm[100010],plen;
void buildmaxfromleft()
{long long int i,j,x,max,g,k,lmax,rmax,t;

 lt[1] = a[1];
    lm[1] = a[1];
    max = a[1];
    for(i = 2;i<=n;i++)
    {
      x = a[i] + lt[i-1];
      if(x>0)
      {
       lt[i] = x;
       if(lt[i]>max)
       {
        max = lt[i];
       }
       lm[i] = max;
      
      }
      
      else
      {
       lt[i] = 0;
       if(a[i]>max)
         max = a[i];
       lm[i] = max;
      
      }
      
    
    }
    
    

}

void buildmaxfromright()
{
long long int i,j,x,max,g,k,lmax,rmax,t;
lt[n] = a[n];
    rm[n] = a[n];
    max = a[n];
    for(i = n-1;i>0;i--)
    {
      x = a[i] + lt[i+1];
      if(x>0)
      {
       lt[i] = x;
       if(lt[i]>max)
       {
        max = lt[i];
       }
       rm[i] = max;
      
      }
      
      else
      {
       lt[i] = 0;
       if(a[i]>max)
         max = a[i];
       rm[i] = max;
      
      }
      
    
    }
}

int main() {
	// your code goes here
long long int i,j,x,max,g,k,lmax,rmax,t;
 scanf("%lld",&t);
 while(t--)
 {
    scanf("%lld %lld",&n,&k);
    for(i = 1;i<=n;i++)
     scanf("%lld",&a[i]);
    buildmaxfromleft();
    buildmaxfromright();
    
    
    max = -999999999999LL;
    x = n-k-1;
    for(i = 1;i<=x;i++)
    {
     lmax = lm[i];
     rmax = rm[i+k+1];
     g = lmax+rmax;
     if(g>max)
       max = g;
    
    }
    
 /* for(i = 1;i<=n;i++)
  printf("%lld ",lm[i]);
  printf("\n");
for(i = 1;i<=n;i++)
  printf("%lld ",rm[i]);
 printf("\n");*/
 printf("%lld\n",max);
  }
	return 0;
}