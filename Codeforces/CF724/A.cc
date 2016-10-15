/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 08 Oct 2016 08:17:33 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::string weeks[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
  std::ios::sync_with_stdio(0);
  std::string a, b;
  std::cin >> a >> b;
  int x = std::find(weeks, weeks + 7, a) - weeks;
  int y = std::find(weeks, weeks + 7, b) - weeks;
  for (int i = 0; i < 11; ++i) {
    if ((y - x + 7) % 7 == days[i] % 7) {
      std::cout << "YES" << std::endl;
      return 0;
    }
  }
  std::cout << "NO" << std::endl;

  return 0;
}
