/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Jan  7 00:04:29 2017
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
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  std::vector<int> numbers;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    numbers.emplace_back(x);
  }
  int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
  if (sum != 0) {
    std::cout << "YES" << std::endl;
    std::cout << 1 << std::endl;
    std::cout << 1 << ' ' << n << std::endl;
  } else {
    for (int i = 0; i < n; ++i) if (numbers[i] != 0) {
      std::cout << "YES" << std::endl;
      std::cout << 2 << std::endl;
      std::cout << 1 << ' ' << i + 1 << std::endl;
      std::cout << i + 2 << ' ' << n << std::endl;
      return 0;
    }
    std::cout << "NO" << std::endl;
  }

  return 0;
}
