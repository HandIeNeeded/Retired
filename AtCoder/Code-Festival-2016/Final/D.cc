/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 27 Nov 2016 12:20:21 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
std::map<int, int> cnt[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    cnt[x % m][x]++;
  }
  int ans = 0;
  for (int i = 1, j = m - 1; i < j; i++, j--) {
    int a = 0, b = 0, c = 0, d = 0;
    for (auto &p: cnt[i]) {
      a += p.second - (p.second & 1);
      b += p.second & 1;
    }
    for (auto &p: cnt[j]) {
      c += p.second - (p.second & 1);
      d += p.second & 1;
    }
    if (b < d) {
      std::swap(b, d);
      std::swap(a, c);
    }
    ans += d;
    b -= d;
    ans += a / 2;
    if (b >= c) {
      ans += c;
    } else {
      ans += b;
      c -= b;
      ans += c / 2;
    }
  }
  int add = 0;
  for (auto &p: cnt[0]) {
    ans += p.second / 2;
    if (p.second & 1) add++;
  }
  ans += add / 2;
  if (!(m & 1)) {
    int add = 0;
    for (auto &p: cnt[m / 2]) {
      ans += p.second / 2;
      if (p.second & 1) add++;
    }
    ans += add / 2;
  }
  std::cout << ans << std::endl;
  return 0;
}
