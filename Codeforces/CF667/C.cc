/*************************************************************************
  > File Name: C.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 30 Apr 2016 12:46:08 AM CST
 *************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 2e4;
char s[N];
int dp[N][2];
int main() {
  ios::sync_with_stdio(0);
  cin >> s;
  int n = strlen(s);
  dp[n - 1][0] = dp[n - 1][1] = 1;
  for (int i = n - 2; i >= 2; i--) {
    if (i == n - 3) {
      dp[i][0] = 1;
    }
    if (i == n - 4) {
      dp[i][1] = 1;
    }
    if (i + 2 < n) {
      if (dp[i + 2][0] && i + 4 < n) {
        if (s[i + 1] != s[i + 3] || s[i + 2] != s[i + 4]) {
          dp[i][0] = 1;
        }
      }
      if (dp[i + 2][1] && i + 5 < n) {
        dp[i][0] = 1;
      }
    }
    if (i + 3 < n) {
      if (dp[i + 3][0] && i + 5 < n) {
        dp[i][1] = 1;
      }
      if (dp[i + 3][1] && i + 6 < n) {
        if (s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5] || s[i + 3] != s[i + 6]) {
          dp[i][1] = 1;
        }
      }
    }
  }
  vector<string> ans;
  for (int i = 4; i < n; i++) {
    if (dp[i][0] && i + 2 < n) {
      ans.push_back(string(s + i + 1, 2));
    }
    if (dp[i][1] && i + 3 < n) {
      ans.push_back(string(s + i + 1, 3));
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << endl;
  for (auto &str: ans) {
    cout << str << endl;
  }
  return 0;
}

