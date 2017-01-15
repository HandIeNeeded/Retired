/*************************************************************************
  >         File: 1023.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Wed Jan  4 21:55:57 2017
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
  int ans = n - 1;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      if (i > 2) ans = std::min(ans, i - 1);
      if (n / i > 2) ans = std::min(ans, n / i - 1);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
