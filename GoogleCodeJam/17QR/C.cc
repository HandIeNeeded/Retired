/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  8 17:39:27 2017
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
    using LL = long long;
    LL number, k;
    std::cin >> number >> k;
    std::set<LL, std::greater<LL>> q;
    LL cnt = 0;
    q.emplace(number);
    std::map<LL, LL> map;
    map[number] = 1;
    while (q.size()) {
      LL n = *q.begin(); q.erase(q.begin());
      LL A = n / 2, B = n - 1 - A;
      cnt += map[n];
      if (cnt >= k) {
        std::cout << "Case #" << cas << ": " << A << ' ' << B << std::endl;
        break;
      }
      map[A] += map[n];
      map[B] += map[n];
      q.emplace(A);
      q.emplace(B);
    }
  }

  return 0;
}
