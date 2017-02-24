/*************************************************************************
  >         File: 1025.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Jan  3 15:39:19 2017
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
  int k;
  std::vector<int> numbers;
  std::cin >> k;
  for (int i = 0; i < k; ++i) {
    int x;
    std::cin >> x;
    numbers.push_back(x);
  }
  sort(numbers.begin(), numbers.end());
  ++k; k >>= 1;
  int ans = 0;
  for (int i = 0; i < k; ++i) ans += (numbers[i] + 1) / 2;
  std::cout << ans << std::endl;
  return 0;
}
