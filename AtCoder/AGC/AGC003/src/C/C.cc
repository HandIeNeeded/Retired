/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 21 Aug 2016 08:31:19 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::vector<int> numbers, a;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    numbers.emplace_back(x);
  }
  a = numbers;
  std::sort(numbers.begin(), numbers.end());
  numbers.resize(std::unique(numbers.begin(), numbers.end()) - numbers.begin());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = std::lower_bound(numbers.begin(), numbers.end(), a[i]) - numbers.begin();
    if (x % 2 != i % 2) ans++;
  }
  assert(ans % 2 == 0);
  std::cerr << ans << std::endl;
  std::cout << ans / 2 << std::endl;
  return 0;
}
