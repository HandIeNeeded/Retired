/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 23 Oct 2016 01:28:31 AM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  int n;
  std::cin >> n;
  std::cin >> s;
  int ans = s.size();
  int now = 0;
  while (now < s.size() && s[now] == '<') ans--, now++;
  now = s.size() - 1;
  while (now >= 0 && s[now] == '>') ans--, now--;
  std::cout << s.size() - ans << std::endl;

  return 0;
}
