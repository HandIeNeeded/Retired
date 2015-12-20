#include <bits/stdc++.h>

#define LL long long
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 55;
const int M = 10005;
int dp[N][N][M];

void toMax(int &x, int y) {
    if (x < y) x = y;
}

pair<int, int> p[N];

int main() {
#ifdef HOME
    freopen("B2.in", "r", stdin);
#endif
    int n, x, y;
    cin >> n >> x >> y;
    REPP(i, 1, n) {
        cin >> p[i].first >> p[i].second;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    REPP(i, 1, n) {
        REP(j, i) {
            REP(k, y + 1) {
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        REPP(j, 1, i) {
            REP(k, y + 1) if (dp[i - 1][j - 1][k] >= 0) {
                if (k + p[i].second > y) {
                    toMax(dp[i][j][y], dp[i - 1][j - 1][k] + (k + p[i].second - y) + p[i].first);
                }
                else {
                    toMax(dp[i][j][k + p[i].second], dp[i - 1][j - 1][k] + p[i].first);
                }
            }
        }
    }
    int ans = -1;
    REPP(j, 1, n) if (dp[n][j][y] >= x) {
        ans = j;
        break;
    }
    cout << ans << endl;

    return 0;
}

