/*************************************************************************
  >         File: 1014.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 16:37:18 2017
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  if (n == 0) {
    std::cout << 10 << std::endl;
  } else if (n == 1) {
    std::cout << 1 << std::endl;
  } else {
    std::vector<int> digits;
    for (int i = 9; i >= 2; --i) {
      if (n % i == 0) {
        while (n % i == 0) {
          digits.push_back(i);
          n /= i;
        }
      }
    }
    if (n > 1) {
      std::cout << -1 << std::endl;
      return 0;
    }
    std::reverse(digits.begin(), digits.end());
    for (auto &d: digits) {
      std::cout << d;
    }
    std::cout << std::endl;
  }
  return 0;
}
