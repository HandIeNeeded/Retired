/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Apr 23 00:58:53 2017
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
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int D, n;
    std::cin >> D >> n;
    double time = 0;
    for (int i = 0; i < n; ++i) {
      int k, s;
      std::cin >> k >> s;
      time = std::max(time, 1.0 * (D - k) / s);
    }
    std::cout << "Case #" << cas << ": ";
    std::cout << std::fixed << std::setprecision(10) << 1.0 * D / time << std::endl;
  }


  return 0;
}
