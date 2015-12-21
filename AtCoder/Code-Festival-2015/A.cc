#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;
const int N = 105;
char mp[N][N];

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif

    int h, w, k;
    cin >> h >> w >> k;
        REP(i, h) REP(j, w) mp[i][j] = '.';
        for (int i = 0; i < h; i += 2) {
            for(int j = 0; j < w; j += 2) {
                if (k) {
                    mp[i][j] = '#';
                    k--;
                }
            }
        }
        if (k) {
            puts("IMPOSSIBLE");
            return 0;
        }
        REP(i, h) {
            puts(mp[i]);
        }
    return 0;
}


