/*************************************************************************
  >         File: A.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat  7 Apr 00:06:54 2018
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

long long cal(std::string s) {
  std::reverse(s.begin(), s.end());
  long long ans = 0;
  long long d = 1;
  for (auto &c: s) {
    if (c == 'S') ans += d;
    else d <<= 1;
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::cout << "Case #" << i + 1 << ": ";
    int D;
    std::string s;
    std::cin >> D >> s;
    std::reverse(s.begin(), s.end());
    int least = std::count(s.begin(), s.end(), 'S');
    if (least > D) {
      std::cout << "IMPOSSIBLE" << std::endl;
      continue;
    } else {
      int count = s.size() * s.size();
      int ans = 0;
      for (int turn = 0; turn < count; ++turn) {
        long long damage = cal(s);
        if (damage <= D) {
          break;
        } else {
          ++ans;
          auto pos = s.find("SC");
          if (pos != std::string::npos) {
            std::swap(s[pos], s[pos + 1]);
          }
        }
      }
      std::cout << ans << std::endl;
    }
  }

  return 0;
}
