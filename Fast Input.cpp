#include<stdio.h>
#define inchar getchar_unlocked
inline int inp() {
      int n=0, ch;
      while((ch = inchar()) < '0');
      n=(ch-'0');
      while((ch=inchar())>='0') n=(n<<3)+(n<<1)+(ch-'0');
      return n;
}


int main()
{
    int n,k,i,j,t;
    t=inp();
    
    printf("%d\n",t);
    return 0;
}
 