/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 24 Sep 2016 08:07:18 PM CST
*************************************************************************/
#include <bits/stdc++.h>

inline int GetDis(char a, char b) {
  if (a == b) return 0;
  return b - 'a' + 'z' - a + 1;
}

char Get(char a, int step) {
  a += step;
  if (a > 'z') a = a - 'z' + 'a' - 1;
  return a;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  int k;
  std::cin >> k;
  for (int i = 0; i < (int) s.size(); ++i) {
    if (s[i] != 'a') {
      int dis = GetDis(s[i], 'a');
      if (dis > k) {
        continue;
      }
      else {
        k -= dis;
        s[i] = 'a';
      }
    }
  }
  if (k > 0) {
    char &c = s.back();
    k %= 26;
    c = Get(c, k);
  }
  std::cout << s << std::endl;
  return 0;
}
