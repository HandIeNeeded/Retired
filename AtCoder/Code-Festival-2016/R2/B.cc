/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 10 Oct 2016 12:54:14 PM CST
*************************************************************************/
#include <bits/stdc++.h>

#define NO std::cout << "No" << std::endl; 
#define YES std::cout << "Yes" << std::endl;

int main() {
  std::ios::sync_with_stdio(0);
  int n, a, b;
  std::cin >> n >> a >> b;
  std::string s;
  std::cin >> s;
  int x = 0, y = 0;
  for (int i = 0; i < (int) s.size(); ++i) {
    if (s[i] == 'c') {
      NO
    }
    else if (s[i] == 'a') {
      if (x + y < a + b) {
        YES
        x++;
      }
      else {
        NO
      }
    }
    else {
      if (x + y < a + b && y < b) {
        YES
        y++;
      }
      else {
        NO
      }
    }
  }


  return 0;
}
