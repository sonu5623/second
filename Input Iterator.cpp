#include <numeric>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream myin("C:\\Users\\Vishwajeet\\Desktop\\a.txt");    
istream_iterator<int> in(myin);   
istream_iterator<int> eos;
cout<<accumulate(in,eos,0); 
getchar();
getchar();    
}
