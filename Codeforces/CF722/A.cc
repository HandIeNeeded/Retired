/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 10:22:57 PM CST
*************************************************************************/
#include <bits/stdc++.h>

void modify(std::string &s) {
  if (s.size() < 2) s = '0' + s;
}

int GetDiff(std::string &a, std::string &b) {
  int ans = 0;
  for (int i = 0; i < (int) a.size(); ++i) {
    ans += a[i] != b[i];
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int type;
  std::string str;
  std::cin >> type >> str;
  int diff = 10;
  std::string best = "";
  for (int i = 0; i < type; ++i) {
    for (int j = 0; j < 60; ++j) {
      int x = i, y = j;
      if (type == 12) x++;
      std::string A = std::to_string(x);
      std::string B = std::to_string(y);
      modify(A), modify(B);
      std::string now = A + ":" + B;
      if (GetDiff(now, str) < diff) {
        diff = GetDiff(now, str);
        best = now;
      }
    }
  }
  std::cout << best << std::endl;
  return 0;
}
