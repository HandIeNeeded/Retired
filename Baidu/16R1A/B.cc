/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 21 May 2016 10:21:08 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 16;
int dp[1 << N][N];
int a[N], p[N];

int main() {
  int t, ca = 1;
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int answer = INT_MIN;
    REP(i, n) cin >> a[i] >> p[i];
    REP(i, n) REP(j, 1 << n) dp[j][i] = INT_MIN;
    REP(i, n) if (p[i] <= 0) dp[1 << i][i] = 0;
    int limit = (1 << n) - 1;
    for (int i = 1; i < limit; i++) {
      for (int j = 0; j < n; j++) if (i & (1 << j)) {
        if (dp[i][j] != INT_MIN) {
          int candidate = limit ^ i;
          int cnt = __builtin_popcount(i);
          for (int k = 0; k < n; k++) if (candidate & (1 << k)) {
            if (p[k] >= 0 && p[k] != cnt) {
              continue;
            }
            dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + a[j] * a[k]);
          }
        }
      }
    }
    for (int i = 0; i < n; i++) answer = max(answer, dp[limit][i]);
    cout << "Case #" << ca++ << ":\n" << answer << endl;
  }


  return 0;
}



