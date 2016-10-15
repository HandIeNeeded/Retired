/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 10 Oct 2016 12:51:15 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::string s = "CODEFESTIVAL2016";
  std::string r;
  std::cin >> r;
  int ans = 0;
  for (int i = 0; i < (int) r.size(); ++i) {
    if (r[i] != s[i]) ans++;
  }
  std::cout << ans << std::endl;


  return 0;
}
