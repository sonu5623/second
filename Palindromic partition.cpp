#include <iostream>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool pal[5003][5003];
// pal[l][r] == true, if s[l..r] is a palindrome, and false otherwise
// It's obsious that pal[i][j] == true if pal[i+1][j-1] == true and s[i] == s[j]
// After it it's easy to cound f[i] - answer for the problem if given string is
// s[1..i]. f[i] = f[j] + 1, if j<=i and pal[(j + 1)..i] == true.
int main(){
    int tc;
    scanf("%d", &tc);
    while (tc--){
        int n;
        scanf("%d\n", &n);
        string s;
        getline(cin, s);
        int i, j, l, r;
        memset(pal, false, sizeof(pal));
//      here we do precalcolation of pal[][]
        for (i = 0; i < n; i++){
            l = r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                pal[l][r] = true;
                l--;
                r++;      
            }
            l = i - 1;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r]){
                pal[l][r] = true;
                l--;
                r++;      
            }
        }
        int f[5003];
        f[0] = 1;
        for (i = 1; i < n; i++){
            f[i] = n + 10;// here we can consider n+10 as INF, because we can cover 
                          // every string with at most n 1-letter strings.
            if (pal[0][i]) f[i] = 1;
            for (j = i; j > 0; j--)
              if (pal[j][i]) f[i] = min(f[i], f[j-1] + 1);
        }
        printf("%d\n", f[n - 1]);
    }
    system("pause");       
}
