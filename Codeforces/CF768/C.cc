/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue 21 Feb 2017 01:17:53 AM JST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n, k, x;
  std::cin >> n >> k >> x;
  std::vector<int> numbers;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    numbers.emplace_back(x);
  }
  std::sort(numbers.begin(), numbers.end());
  if (k & 1) {
    for (int i = 0; i < n; ++i) numbers[i] = (i & 1) ? numbers[i] : numbers[i] ^ x;
  }
  std::cout << *std::max_element(numbers.begin(), numbers.end()) << ' ' << *std::min_element(numbers.begin(), numbers.end()) << std::endl;

  return 0;
}
