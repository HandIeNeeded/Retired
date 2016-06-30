/*************************************************************************
	> File Name: E.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 30 Jun 2016 02:15:21 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 505;
bitset<N> dp[N], tmp[N], can;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  dp[0].set(N - 1);
  dp[0].set(0);
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  REPP(i, 1, n) cin >> a[i];
  REPP(i, 1, n) {
    REP(j, k + 1) tmp[j] = dp[j];
    for (int j = k; j >= 0; j--) if (dp[j].test(N - 1) && j + a[i] <= k) {
      bitset<N> now = dp[j] | (dp[j] << a[i]);
      dp[j + a[i]] |= now;
    }
  }
  can = dp[k];
  REP(i, k + 1) if (can.test(i)) ans.push_back(i);
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << endl;
  for (auto &x: ans) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
