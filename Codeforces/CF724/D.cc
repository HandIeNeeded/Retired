/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 08 Oct 2016 09:09:40 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 111111;
#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID 
#define RC R, MID + 1, r

int qx, qd, ql, qr;

bool can[N];
const int inf = 1 << 30;

struct Segment {
  int a[N << 2], b[N << 2];

  void build(int x, int l, int r) {
    if (l == r) a[x] = inf, b[x] = l;
    else {
      build(LC), build(RC);
      a[x] = inf, b[x] = l;
    }
  }

  void merge(int x, int l, int r) {
    if (a[L] < a[R]) {
      a[x] = a[L];
      b[x] = b[L];
    }
    else {
      a[x] = a[R];
      b[x] = b[R];
    }
  }

  void update(int x, int l, int r) {
    if (l == r) {
      a[x] = std::min(a[x], qd);
    }
    else {
      if (qx <= MID) update(LC);
      if (qx > MID) update(RC);
      merge(x, l, r);
    }
  }

  std::pair<int, int> query(int x, int l, int r) {
    if (ql > qr) return {0, 0};
    if (ql <= l && qr >= r) return {a[x], b[x]};
    else {
      std::pair<int, int> a = {inf + 1, -1}, b = {inf + 1, -1};
      if (ql <= MID) a = query(LC);
      if (qr > MID) b = query(RC);
      if (a.first < b.first) return a;
      return b;
    }
  }
}T[2];

std::pair<int, int> dp[N][2];

int main() {
  std::ios::sync_with_stdio(0);
  int m;
  std::cin >> m;
  std::string s;
  std::cin >> s;
  if (m == 1) {
    std::sort(s.begin(), s.end());
    std::cout << s << std::endl;
    return 0;
  }
  int n = s.size();
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 2; ++j) T[j].build(1, 1, n);
    for (int j = 0; j < N; ++j) for (int k = 0; k < 2; ++k) dp[j][k] = {inf, 0};
    for (int j = 0; j < n; ++j) {
      if (s[j] <= 'a' + i) can[j + 1] = 1;
    }
    for (int j = 1; j <= n; ++j) {
      if (can[j]) {
        int cost = s[j - 1] == 'a' + i;
        dp[j][1] = std::min(dp[j][1], {dp[j - 1][0].first + cost, dp[j - 1][0].second});
        ql = std::max(1, j - m), qr = j - 1;
        std::pair<int, int> res = T[1].query(1, 1, n);
        dp[j][1] = std::min(dp[j][1], {res.first + cost, res.second});
        dp[j][1] = std::min(dp[j][1], {inf, 0});
      }
      else {
        dp[j][1] = {inf, 0};
      }
      ql = std::max(1, j - m + 1), qr = j - 1;
      dp[j][0] = T[1].query(1, 1, n);
      if (j < m) dp[j][0] = {0, 0};
      qx = j, qd = dp[j][1].first;
      T[1].update(1, 1, n);
    }
    std::pair<int, int> ans = std::min(dp[n][0], dp[n][1]);
    //for (int i = 1; i <= n; ++i) {
    //  for (int j = 0; j < 2; ++j) {
    //    std::cout << dp[i][j].first << ' ';
    //  }
    //  std::cout << std::endl;
    //}
    if (ans.first < inf) {
      std::string res;
      for (int j = 0; j < n; ++j) {
        if (s[j] < 'a' + i) {
          res += s[j];
        }
      }
      std::sort(res.begin(), res.end());
      //std::cerr << "# ans.first # is " << ans.first << std::endl;
      //std::cerr << "# ans.second # is " << ans.second << std::endl;
      res += std::string(ans.first, 'a' + i);
      std::cout << res << std::endl;
      return 0;
    }
  }

  return 0;
}
