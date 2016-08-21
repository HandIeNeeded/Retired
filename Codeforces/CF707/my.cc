#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  using LL = long long;
  LL a;
  std::cin >> a;
  for (int i = 1; i <= a; ++i) {
    if (a * a % i == 0 && (a * a / i + i) % 2 == 0) {
      LL c = (a * a / i + i) / 2;
      LL b = c - i;
      if (!c || !b) {
        std::cout << "-1" << std::endl; return 0;
      }
      std::cout << b << ' ' << c << std::endl;
      return 0;
    }
  }
  return 0;
}
