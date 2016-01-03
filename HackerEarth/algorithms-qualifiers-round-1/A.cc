/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 04 Jan 2016 12:12:47 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
char s[N];

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);
        if (n >= 10) {
            puts("YES");
        }
        else {
            int find = 0;
            REPP(i, 1, n - 1) {
                string a = string(s, i);
                REPP(j, i + 1, n - 1) {
                    string b = string(s + i, j - i);
                    if (b == a) continue;
                    REPP(k, j + 1, n - 1) {
                        string c = string(s + j, k - j);
                        if (c == a || c == b) continue;
                        string d = string(s + k);
                        if (d == a || d == b || d == c) continue;
                        puts("YES");
                        find = 1;
                        break;
                    }
                    if (find) break;
                }
                if (find) break;
            }
            if (!find) puts("NO");
        }
    }


    return 0;
}


