/*************************************************************************
  >         File: D.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 28 Aug 2016 08:15:15 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

void OK(LL base) {
  std::cout << base << std::endl;
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(0);
  LL n, s;
  std::cin >> n >> s;
  if (s == n) {
    OK(n + 1);
  }
  static const int K = 1e6;
  for (int base = 2; base < K; base++) {
    LL tmp = n, sum = 0;
    while (tmp) {
      sum += tmp % base;
      tmp /= base;
    }
    if (sum == s) {
      OK(base);
    }
  }
  LL answer = LLONG_MAX;
  for (int coef = K - 1; coef >= 1; coef--) {
    LL left = s - coef;
    if (left < 0) continue;
    if ((n - left) % coef == 0) {
      LL base = (n - left) / coef;
      if (left < base && coef < base) {
        answer = std::min(answer, base);
      }
    }
  }
  std::cerr << "answer: " << answer << std::endl;
  if (answer != LLONG_MAX) OK(answer);
  std::cout << -1 << std::endl;
  return 0;
}
