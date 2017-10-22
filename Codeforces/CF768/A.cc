/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue 21 Feb 2017 01:06:50 AM JST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::vector<int> numbers;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    numbers.push_back(x);
  }
  int mi = *std::min_element(numbers.begin(), numbers.end());
  int mx = *std::max_element(numbers.begin(), numbers.end());
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (numbers[i] != mi && numbers[i] != mx) cnt++;
  }
  std::cout << cnt << std::endl;
  return 0;
}
