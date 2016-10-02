/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 10:18:12 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int p[111];

std::string chars = "aeiouy";

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  std::string string;
  std::getline(std::cin, string);
  bool bad = false;
  for (int i = 0; i < n; ++i) {
    std::getline(std::cin, string);
    int cnt = 0;
    for (int i = 0; i < (int) string.size(); ++i) {
      cnt += chars.find(string[i]) != std::string::npos;
    }
    bad |= cnt != p[i];
  }
  bad ? puts("NO") : puts("YES");

  return 0;
}
