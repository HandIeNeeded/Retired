/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Wed 14 Sep 2016 01:03:03 AM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

std::string Get(LL x) {
  std::string answer(18, '0');
  int now = 0;
  while (x) {
    answer[now++] = '0' + ((x % 10) & 1);
    x /= 10;
  }
  std::reverse(answer.begin(), answer.end());
  return answer;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::map<std::string, int> mp;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string c;
    std::cin >> c;
    if (c[0] == '+') {
      LL x;
      std::cin >> x;
      mp[Get(x)]++;
    }
    else if (c[0] == '-') {
      LL x;
      std::cin >> x;
      mp[Get(x)]--;
    }
    else {
      std::string pattern;
      std::cin >> pattern;
      pattern = std::string(18 - pattern.size(), '0') + pattern;
      std::cout << mp[pattern] << std::endl;
    }
  }


  return 0;
}
