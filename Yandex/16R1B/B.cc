/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 02:34:23 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 26;
int cost[N];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  REP(i, N) cost[i] = INT_MAX;
  REP(i, m) {
    string str;
    int x, y;
    cin >> x >> y >> str;
    REP(i, x) cost[str[i] - 'a'] = min(cost[str[i] - 'a'], y);
  }
  int ans = 0;
  REP(i, n) {
    if (cost[s[i] - 'a'] == INT_MAX) {
      cout << -1 << endl;
      return 0;
    }
    else {
      ans += cost[s[i] - 'a'];
    }
  }
  cout << ans << endl;


  return 0;
}


