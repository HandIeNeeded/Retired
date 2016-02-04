/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Fri 05 Feb 2016 01:21:09 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
const int N = 505;
int mp[N][N], col[N];
int n, m;

bool dfs(int x, int c = 0) {
    //cout << x << "hehe" << endl;
    bool bad = 1;
    REPP(i, 1, n) if (x != i && mp[x][i] == 0) {
        if (col[i] != 2) {
            if (col[i] != 1 - c) return 0;
        }
        else {
            col[i] = 1 - c;
            bad &= dfs(i, col[i]);
        }
    }
    return bad;
}

int cnt[N];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
    cin >> n >> m;
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        mp[x][y] = mp[y][x] = 1;
    }
    REPP(i, 1, n) {
        REPP(j, 1, n) {
            if (mp[i][j]) cnt[i]++;
        }
    }
    REPP(i, 1, n) col[i] = 2;
    int good = 1;
    REPP(i, 1, n) if (cnt[i] != n - 1 && col[i] == 2) {
        col[i] = 0;
        good &= dfs(i);
    }
    !good ? puts("No") : puts("Yes");
    if (good) {
        REPP(i, 1, n) {
            if (col[i] == 2) {
                cout << 'b';
            }
            else {
                if (col[i]) cout << 'a';
                else cout << 'c';
            }
        }
        cout << endl;
    }
    return 0;
}
