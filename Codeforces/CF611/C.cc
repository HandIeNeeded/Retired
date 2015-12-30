/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Wed 30 Dec 2015 11:21:00 PM CST
 ************************************************************************/
#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 505;
int f[N][N], g[N][N];
char mp[N][N];

int get(int x, int y, int z, int w) {
    int a = f[z - 1][w] - f[x - 1][w] - f[z - 1][y - 1] + f[x - 1][y - 1];
    int b = g[z][w - 1] - g[x - 1][w - 1] - g[z][y - 1] + g[x - 1][y - 1];
    return a + b;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    REPP(i, 1, n) {
        cin >> mp[i] + 1;
    }
    REPP(i, 1, n - 1) {
        REPP(j, 1, m) {
            if (mp[i][j] == '#') continue;
            if (mp[i + 1][j] == '#') continue;
            f[i][j] = 1;
        }
    }
    REPP(i, 1, n - 1) {
        REPP(j, 1, m) {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    REPP(i, 1, n) {
        REPP(j, 1, m - 1) {
            if (mp[i][j] == '#') continue;
            if (mp[i][j + 1] == '#') continue;
            g[i][j] = 1;
        }
    }
    REPP(i, 1, n) {
        REPP(j, 1, m - 1) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        cout << get(x, y, z, w) << endl;
    }

    return 0;
}


