/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 20 Oct 2016 09:09:30 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  using LL = long long;
  LL a[3];
  for (int i = 0; i < 3; ++i) std::cin >> a[i];
  LL id = std::max_element(a, a + 3) - a;
  LL sum = std::accumulate(a, a + 3, 0LL);
  LL answer = LLONG_MAX;
  for (int left = 0; left < 3; ++left) {
    for (int right = 0; right < 3; ++right) {
      LL b[3];
      for (int i = 0; i < 3; ++i) if (i == id) b[i] = a[i]; else b[i] = a[id] - 1;
      for (int i = 0; i < left; ++i) {
        b[(id + 2 - i) % 3]++;
      }
      for (int i = 0; i < right; ++i) {
        b[(id + i + 1) % 3]++;
      }
      bool bad = 0;
      for (int i = 0; i < 3; ++i) if (b[i] < a[i]) {
        bad = 1;
        break;
      }
      if (bad) continue;
      LL diff = std::accumulate(b, b + 3, 0LL) - sum;
      if (diff < answer) {
        std::cerr << "[Line #" << __LINE__ << "] fuck !!!" << std::endl;
        for (int i = 0; i < 3; ++i) {
          std::cerr << "# b[i] # is " << b[i] << std::endl;
        }
        answer = diff;
      }
    }
  }
  std::cout << answer << std::endl;
  return 0;
}
