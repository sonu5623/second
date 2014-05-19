#include <stdio.h>
#include <stdlib.h>
int n,i,j,k,a[100][100],b[100][100],c;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        {
          scanf("%d",&a[i][j]);               
        }
      for(k=1;k<=n;k++)
       {
          if(k%2==1)
          {
               for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        {
                       c=a[i][k]+a[k][j];
          b[i][j] = (a[i][j]<c?a[i][j]:c);               
        }        
          }
          else
          {
             for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        {
                       c=b[i][k]+b[k][j];
          a[i][j] = (b[i][j]<c?b[i][j]:c);               
        }      
          }                
       }
    if(n%2==1)
    {
            for(i=1;i<=n;i++)
            {
      for(j=1;j<=n;j++)
        {
              printf("%d ",b[i][j]);         
        }    
        printf("\n");
        }
    }
    else
    {
        for(i=1;i<=n;i++)
            {
      for(j=1;j<=n;j++)
        {
              printf("%d ",a[i][j]);         
        }    
        printf("\n");
        }
    }


return 0;    
}
