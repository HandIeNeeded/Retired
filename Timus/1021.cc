/*************************************************************************
  >         File: 1021.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Thu Jan  5 19:00:09 2017
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
  std::sort(numbers.begin(), numbers.end());
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    x = 10000 - x;
    if (*std::lower_bound(numbers.begin(), numbers.end(), x) == x) {
      std::cout << "YES" << std::endl;
      return 0;
    }
  }
  std::cout << "NO" << std::endl;
  return 0;
}
