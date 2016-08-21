/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 20 Aug 2016 09:17:10 PM CST
*************************************************************************/
#include <bits/stdc++.h>

using LL = long long;

LL Sqr(int x) {
  return 1LL * x * x;
}

//2uv
void solve1(int x) {
  if (x & 1) return ;
  int y = x >> 1;
  for (int i = 1; i * i < y; i++) if (y % i == 0) {
    int a = i, b = y / i;
    std::cout << Sqr(b) - Sqr(a) << ' ' << Sqr(b) + Sqr(a) << std::endl;
    exit(0);
  }
}

//u2 - v2
void solve2(int x) {
  for (int i = 1; i * i < x; i++) if (x % i == 0) {
    int a = i, b = x / i;
    if (a % 2 != b % 2) continue;
    if (a < b) std::swap(a, b);
    int p = (a + b) >> 1, q = (a - b) >> 1;
    std::cout << Sqr(p) + Sqr(q) << ' ' << 2LL * p * q << std::endl;
    exit(0);
  }
}

//u2 + v2
void solve3(int x) {
  for (int i = 1; i * i < x; i++) {
    int y = x - i * i;
    int rt = sqrt(y + 0.5);
    if (Sqr(rt) != y) continue;
    if (rt < i) std::swap(rt, i);
    if (rt == i) continue;
    std::cout << Sqr(rt) - Sqr(i) << ' ' << 2LL * rt * i << std::endl;
    exit(0);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  solve1(n);
  solve2(n);
  solve3(n);
  std::cout << -1 << std::endl;
  return 0;
}
