/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 16 Apr 2016 08:59:35 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1005;
char s[N];

int main() {
    int t, ca = 1;
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);
        string ans;
        REP(i, n) {
            if (ans == "" || s[i] >= ans[0]) ans = s[i] + ans;
            else ans = ans + s[i];
        }
        printf("Case #%d: %s\n", ca++, ans.c_str());
    }

    return 0;
}

