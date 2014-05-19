#include <iostream>
using namespace std;
#define p 1000000007
#define ll long long
long long int n,a[100],i,s,j,br,ans,lob,t;
ll pow(ll a, ll b){
  ll r;
  if(b==0) return 1;
  r = pow(a,b/2);
  r = (r*r)%p;
  if(b%2) r = (r*a)%p;
  return r;
}
 
int main() {
	// your code goes here
	scanf("%lld",&t);
	while(t--)
	{
	  	scanf("%lld",&n);
	  	ans = pow(2,n);
	  	ans = ans-1;
	    printf("%lld\n",ans);
	}
	return 0;
}