/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 20 Oct 2016 09:27:00 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  int a, b;
  std::cin >> a >> b;
  int now = 1;
  while (1) {
    int A = a * now++;
    if (A % 10 == b || A % 10 == 0) {
      std::cout << now - 1 << std::endl;
      return 0;
    }
  }


  return 0;
}
