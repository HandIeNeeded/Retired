/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 23 Oct 2016 09:46:01 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  auto pos = s.find_first_of('C');
  if (pos == std::string::npos) {
    puts("No");
    return 0;
  }
  pos = s.find('F', pos);
  if (pos == std::string::npos) {
    puts("No");
    return 0;
  }
  puts("Yes");


  return 0;
}
