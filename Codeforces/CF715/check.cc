/*************************************************************************
  >         File: check.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 11:26:32 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

LL Sqrt(LL x) {
  LL rt = sqrt(x + 0.5);
  //while ((rt + 1) * (rt + 1) <= x) rt++;
  //while ((rt - 1) * (rt - 1) >= x) rt--;
  return rt;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::ifstream dataIn("data.in");
  std::ifstream outIn("my.out");
  int n;
  dataIn >> n;
  std::cerr << "Test Case: " << n << std::endl;
  LL now = 2;
  for (int i = 1; i <= n; ++i) {
    LL x;
    outIn >> x;
    //std::cerr << i << ' ' << x << std::endl;
    now += x * i;
    LL rt = Sqrt(now);
    if (rt * rt != now || rt % (i + 1)) {
      std::cerr << "WA" << std::endl;
      return -1;
    }
    now = rt;
  }
  std::cerr << "AC" << std::endl;

  return 0;
}
