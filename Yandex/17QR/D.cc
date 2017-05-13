/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Apr 30 09:50:18 2017
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
  for (int i = 0; i < T; ++i) {
    using LL = long long;
    LL n;
    std::cin >> n;
    for (int i = 1; i <= 60; ++i) {
      LL nn = n * i;
      if (__builtin_popcountl(nn) <= i) {
        std::priority_queue<int> q;
        for (int i = 60; i >= 0; --i) {
          if (nn & (1LL << i)) {
            q.push(i);
          }
        }
        while (q.size() < i) {
          int x = q.top(); q.pop();
          q.push(x - 1), q.push(x - 1);
        }
        std::cout << i;
        while (q.size()) {
          std::cout << " " << q.top();
          q.pop();
        }
        std::cout << std::endl;
        break;
      }
    }
  }

  return 0;
}
