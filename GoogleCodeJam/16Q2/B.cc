/*************************************************************************
	> File Name: B.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 28 May 2016 10:25:20 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 205;
long double p[N], dp[N][N];
int n, k;

long double calc(vector<long double>& p) {
  REP(i, k + 1) REP(j, k + 1) dp[i][j] = 0.0;
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][j] * (1.0 - p[i - 1]);
      }
      else {
        dp[i][j] = dp[i - 1][j] * (1.0 - p[i - 1]) + dp[i - 1][j - 1] * p[i - 1];
      }
    }
  }
  return dp[k][k / 2];
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    REPP(i, 1, n) cin >> p[i];
    sort(p + 1, p + n + 1);
    long double answer = 0;
    for (int i = 0; i <= k; i++) {
      vector<long double> p;
      for (int j = 0; j < i; j++) {
        p.push_back(::p[j + 1]);
      }
      for (int j = 0; j < k - i; j++) {
        p.push_back(::p[n - j]);
      }
      answer = max(answer, calc(p));
    }
    cout << "Case #" << ca++ << ": " << fixed << setprecision(10) << answer << endl;
  }
  return 0;
}



