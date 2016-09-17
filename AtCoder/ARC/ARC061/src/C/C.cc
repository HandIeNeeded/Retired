/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 12 Sep 2016 11:19:31 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

LL Get(int x) {
  if (x <= 1) return 1;
  else return 1LL << (x - 1);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::string string;
  std::cin >> string;
  LL answer = 0;
  for (int i = 0; i < (int) string.size(); ++i) {
    for (int j = i + 1; j <= (int) string.size(); ++j) {
      auto value = std::stoll(string.substr(i, j - i));
      answer += Get(i) * Get(string.size() - j) * value;
    }
  }
  std::cout << answer << std::endl;
  return 0;
}
