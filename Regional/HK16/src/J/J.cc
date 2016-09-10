/*************************************************************************
  >         File: J.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 04:17:32 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 5e5 + 5;
const int MO = 1e9 + 7;
int pw[N];

int get(int x) {
  if (x < 0) return 0;
  return pw[x];
}

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  int k = std::count(s.begin(), s.end(), '?');

  pw[0] = 1;
  for (int i = 1; i <= k; i++) {
    pw[i] = pw[i - 1] << 1;
    pw[i] %= MO;
  }
  int ans = 0;
  for (int i = 0; i < (int) s.size(); ++i) {
    auto c = s[i];
    if (c == '0') {
      Add(ans, 1LL * get(k - 1) * cnt2 % MO);
      Add(ans, 1LL * get(k) * cnt1 % MO);
      cnt0++;
    } else if (c == '1') {
      cnt1++;
    } else {
      Add(ans, 1LL * get(k - 2) * cnt2 % MO);
      Add(ans, 1LL * get(k - 1) * cnt1 % MO);
      cnt2++;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}
