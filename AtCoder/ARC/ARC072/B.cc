/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr 22 21:22:54 2017
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
  using LL = long long;
  LL a, b;
  std::cin >> a >> b;
  int ans = 0;
  while (std::max(a, b) > 1) {
    if (a < b) std::swap(a, b);
    LL k = a >> 1;
    a -= k << 1;
    b += k;
    ans ^= 1;
    std::cerr << "# a << ' ' << b # is " << a << ' ' << b << std::endl;
  }
  ans ? puts("Alice") : puts("Brown");

  return 0;
}
