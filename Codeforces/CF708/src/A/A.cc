/*************************************************************************
  >         File: A.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 25 Aug 2016 12:37:07 AM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  auto front = s.find_first_not_of('a');
  if (front == std::string::npos) {
    s.back() = 'z';
    std::cout << s << std::endl;
    return 0;
  }
  auto rear = s.find_first_of('a', front);
  if (rear == std::string::npos) rear = s.size();
  for (auto i = front; i < rear; i++) {
    s[i]--;
  }
  std::cout << s << std::endl;
  return 0;
}
