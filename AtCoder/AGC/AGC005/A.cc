/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 08:02:26 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  int now = 0;
  int answer = 0;
  for (int i = 0; i < (int) s.size(); ++i) {
    if (s[i] == 'T') now--;
    else now++;
    if (now < 0) {
      answer++;
      now = 0;
    }
  }
  answer += now;
  std::cout << answer << std::endl;


  return 0;
}
