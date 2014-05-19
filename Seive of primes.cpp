#include <iostream>
using namespace std;

int visited[1000100],prime[200000];
int buildseive(int n)
{
int i,j,x,y;
  for(i = 2;i<=n;i++)
    visited[i] = 0;
    j = 0;
    for(i = 2;i<=n;i++)
    {
      if(visited[i] == 0)
      {
       prime[j] = i;
       j++;
      }
      x = 2;
      y = x*i;
      while(y<=n)
      {
        visited[y] = 1;
        x++;
        y = x*i;
      }
    }
    return j-1;

}
int main() {
	// your code goes here
	int nop = buildseive(1000000);
	int i = 0;
	printf("%d\n",nop);
	for(i = 0;i<30;i++)
	 printf("%d ",prime[i]);
	return 0;
}
