/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 24 Jan 2016 02:41:38 AM CST
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 3006;
double dp[N];
double p[N][N], g[N];
double A, B;
int n, k;

void init() {
    memset(p, 0, sizeof(p));
    memset(g, 0, sizeof(g));
    p[0][0] = 1.0;
    REPP(i, 1, n) {
        REPP(j, 0, i) {
            if (j == 0) p[i][j] = pow(B, i);
            else p[i][j] = p[i - 1][j] * B + p[i - 1][j - 1] * A;
        }
        g[i] = 0.0;
        REPP(j, k, i) g[i] += p[i][j];
    }
}

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        double p;
        scanf("%d%d", &n, &k);
        scanf("%lf", &p);
        A = p, B = 1.0 - p;
        init();
        REPP(i, 1, n) dp[i] = 0;
        REPP(i, 0, k - 1) dp[i] = 0;
        REPP(i, k, n) {
            REPP(j, k, i) {
                dp[i] = max(dp[i], dp[i - j] + g[j]);
            }
        }
        printf("Case #%d: %.10f\n", ca++, dp[n]);
    }

    return 0;
}

