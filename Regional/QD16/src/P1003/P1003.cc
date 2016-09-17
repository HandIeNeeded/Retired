/*************************************************************************
  >         File: P1003.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 12:35:50 PM CST
*************************************************************************/
#include <bits/stdc++.h>

char s[1111111];
double answer[1111111];
double limit = acos(-1.0) * acos(-1.0) / 6;

int main() {
  for (int i = 1; i <= 1111111; ++i) answer[i] += answer[i - 1] + 1.0 / i / i;
  while (scanf("%s", s) > 0) {
    std::string str(s);
    auto position = str.find_first_not_of('0');
    str = str.substr(position);
    if (str.size() > 6) {
      printf("%.5f\n", limit);
    }
    else {
      auto n = std::stoi(str);
      printf("%.5f\n", answer[n]);
    }
  }

  return 0;
}
