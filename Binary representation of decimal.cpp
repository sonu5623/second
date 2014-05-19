#include <iostream>
using namespace std;
int n,a[100],i,s,j;

int binrep(int n)
{
 i = 0,s = 0;
 while(n)
 {
 a[i++] = n%2;
 n = n/2;
 }

 i--;
 while(i>=0)
 {
 s = s*10;
 s = s+a[i];
 i--;
 }
 return s;
}


int main() {
	// your code goes here
	scanf("%d",&n);
	printf("\n%d",binrep(n));
	return 0;
}