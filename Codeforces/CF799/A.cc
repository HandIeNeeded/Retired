/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri May 12 00:04:47 2017
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
  int n, t, d, k;
  std::cin >> n >> t >> k >> d;
  int lo = 0, hi = 1e6;
  int A = (n + k - 1) / k * t, B;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    int cnt = mid / t * k;
    int cnt2 = (mid - d) / t * k;
    if (cnt + cnt2 < n) lo = mid;
    else hi = mid;
  }
  B = hi;
  std::cerr << "# A << ' ' << B # is " << A << ' ' << B << std::endl;
  if (A > B) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;

  return 0;
}
