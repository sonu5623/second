#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
// Segment Tree Library
// The segment tree is stored like a heap array
#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2
#define ll long long int
vector<ll> segment_tree;
 
long long int A[1000010],len=0,ans;
    
    long long int n,i,q,ind,val;
    char name[5];
 
inline void init_segment_tree(ll N) { // if original array size is N,
// the required segment_tree array length is 2*2^(floor(log2(N)) + 1);
ll length = (ll)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
segment_tree.resize(length, 0); // resize this vector and fill with 0
}
 
 
inline void build_segment_tree( ll node, ll b, ll e) {
if (b == e) { // as b == e, either one is fine
segment_tree[node] = A[b]; // store value of this cell
 
}
 
else { // recursively compute the values in the left and right subtrees
ll leftIdx = 2 * node, rightIdx = 2 * node + 1;
build_segment_tree(leftIdx , b , (b + e) / 2);
build_segment_tree( rightIdx, (b + e) / 2 + 1, e );
ll lContent = segment_tree[leftIdx], rContent = segment_tree[rightIdx];
 // make this segment contains sum of left and right subtree
segment_tree[node] = lContent + rContent;
 
 
 
 } }
 
 
inline ll query( ll node, ll b, ll e, ll i, ll j) {
if (i > e || j < b) return -1; // if the current interval does not intersect query interval
if (b >= i && e <= j) return segment_tree[node]; // if the current interval is inside query interval
// compute the minimum position in the left and right part of the interval
ll p1 = query(2 * node , b , (b + e) / 2, i, j);
ll p2 = query(  2 * node + 1, (b + e) / 2 + 1, e , i, j);
// return the position where the overall minimum is
if (p1 == -1) return p2; // can happen if we try to access segment outside query
if (p2 == -1) return p1; // same as above
 return p1 + p2;
 
}
 
 
inline void update(  ll node, ll l, ll r, ll i, ll j)
{
 
  segment_tree[node]+=j;
  if(l == r)
  return;
  ll lin,rin,p,x;
  lin = 2*node;
  rin = lin+1;
  p = (l+r)/2;
  x = p+1;
  if(i<=p)
  update(lin,l,p,i,j);
  else
  update(rin,x,r,i,j);
  
}
 
 
 
 
int main() {
//ll A[] = {8,7,3,9,5,1,10};
  scanf("%lld",&n);
     scanf("%lld",&q);
    for(i = 0;i<n;i++)
       scanf("%lld",&A[i]);
 
init_segment_tree(n); build_segment_tree( 1, 0, n-1);
//for(i = 1;i<=10;i++)
 //printf("%lld %lld\n",i,segment_tree[i]);
while(q--)
    {
    scanf("%s %lld %lld",name,&ind,&val);
    if(name[0] == 'S')
    {
        
    printf("%lld\n", query(1, 0, n-1,  ind, val));
    }
 
   else if(name[0] == 'G')
   {
      // Update
    update( 1, 0, n-1, ind, val);
   
   }
 
    else 
   {
      // Update
    update( 1, 0, n-1, ind, -val);
   
   }
 
    
     }
 
//for(i = 1;i<=10;i++)
 //printf("%lld %lld\n",i,segment_tree[i]);
 
return 0;
} 
