/*************************************************************************
  >         File: B.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Thu 25 Aug 2016 01:16:38 AM CST
*************************************************************************/
#include <bits/stdc++.h>

int Get(int number) {
  int rt = std::sqrt(2 * number + 0.5);
  while (1LL * rt * (rt + 1) < 2 * number) rt++;
  while (1LL * rt * (rt + 1) > 2 * number) rt--;
  if (1LL * rt * (rt + 1) != 2 * number) {
    std::cout << "Impossible" << std::endl;
    exit(0);
  }
  return rt + 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  int a[2][2] = {0};
  using LL = long long;
  LL sum = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cin >> a[i][j];
      sum += a[i][j];
    }
  }
  int x, y;
  x = Get(a[0][0]), y = Get(a[1][1]);
  if (sum == 0) {
    std::cout << 1 << std::endl;
    exit(0);
  } else if (sum == a[0][0]) {
    std::cout << std::string(x, '0') << std::endl;
    exit(0);
  } else if (sum == a[1][1]) {
    std::cout << std::string(y, '1') << std::endl;
    exit(0);
  } else {
    std::cerr << x << ' ' << y << std::endl;
    if (a[0][1] + a[1][0] != 1LL * x * y) {
      std::cout << "Impossible" << std::endl;
      exit(0);
    }
    int k = a[1][0] / x, b = a[1][0] % x;
    std::string answer(k, '1');
    answer += std::string(x, '0');
    auto position = answer.size() - b;
    if (b) {
      answer.insert(position, 1, '1');
      answer += std::string(y - k - 1, '1');
    }
    else {
      answer += std::string(y - k, '1');
    }
    std::cout << answer << std::endl;
  }

  return 0;
}
