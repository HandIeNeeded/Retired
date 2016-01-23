/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> created Time: Sun 24 Jan 2016 01:53:36 AM CST
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int N = 1e5 + 5;
const int M = 27;
char s[2][N];
int last[M];
int pre[N][M];
int prefix[N][M], suffix[N][M];

int main() {
#ifdef HOME
    string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
    freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
    int t, ca = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        REP(i, 2) {
            scanf("%s", s[i] + 1);
        }
        cout << s[0] + 1 << endl;
        cout << s[1] + 1 << endl;
        REP(i, M) prefix[0][i] = suffix[n + 1][i] = 0;
        REP(i, M) last[i] = 0;
        REPP(i, 1, n) {
            REP(j, M) pre[i][j] = last[j];
            last[s[1][i] - 'A'] = i;
            REP(j, M - 1) {
                if (j == s[1][i] - 'A') {
                    prefix[i][j] = prefix[i - 1][26];
                }
                else {
                    prefix[i][j] = prefix[pre[i][s[1][i] - 'A']][s[1][i] - 'A'] + 1;
                }
            }
            int &ans = prefix[i][26];
            ans = n + 1;
            REP(j, M - 1) ans = min(ans, prefix[i][j]);
        }
        REP(j, M) last[j] = n + 1;
        for (int i = n; i >= 1; i--) {
            REP(j, M - 1) pre[i][j] = last[j];
            last[s[1][i] - 'A'] = i;
            REP(j, M - 1) {
                if (j == s[1][i] - 'A') {
                    suffix[i][j] = suffix[i + 1][26];
                }
                else {
                    suffix[i][j] = suffix[pre[i][s[1][i] - 'A']][s[1][i] - 'A'] + 1;
                }
            }
            int &ans = suffix[i][26];
            ans = n + 1;
            REP(j, M - 1) ans = min(ans, suffix[i][j]);
        }
        int ans = min(prefix[n][s[0][n] - 'A'], suffix[1][s[0][1] - 'A']);
        REPP(i, 1, n - 1) if (s[0][i] != s[1][i]) {
            ans = min(ans, prefix[i][s[0][i] - 'A'] + suffix[i + 1][s[0][i] - 'A']);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }

    return 0;
}

