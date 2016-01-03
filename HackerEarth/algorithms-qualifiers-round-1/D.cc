/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 04 Jan 2016 12:57:13 AM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1e5 + 5;
int f[N], a[2][N], mp[N], vis[N];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
#ifdef HOME
    freopen("D.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        REPP(i, 1, n) f[i] = i, vis[i] = 0;
        REP(i, 2) {
            REPP(j, 1, n) scanf("%d", &a[i][j]);
        }
        REPP(i, 1, n) {
            mp[a[0][i]] = i;
        }
        REPP(i, 1, n) {
            a[1][i] = mp[a[1][i]];
        }
        int bad = 0;
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            int tx = find(x), ty = find(y);
            if (tx == ty) continue;
            else {
                f[tx] = ty;
            }
        }
        REPP(i, 1, n) if (!vis[i]) {
            int x = a[1][i], y;
            vis[i] = 1, y = i;
            while (!vis[x]) {
                int tx = find(y), ty = find(x);
                if (tx != ty) {
                    bad = 1;
                    break;
                }
                vis[x] = 1, y = x, x = a[1][x];
            }
            if (bad) break;
        }
        if (bad) puts("NO");
        else {
            puts("YES");
        }
    }


    return 0;
}


