/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat 14 Apr 03:05:45 2018
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

const int N = 1111;
int M[N], S[N], P[N];

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    std::cout << "Case #" << cas + 1 << ": ";
    int R, B, C;
    std::cin >> R >> B >> C;
    for (int i = 0; i < C; ++i) {
      std::cin >> M[i] >> S[i] >> P[i];
    }
    using LL = long long;
    LL lo = 0, hi = 4e18;
    while (lo + 1 < hi) {
      LL mid = (lo + hi) >> 1;
      std::vector<LL> can;
      for (int i = 0; i < C; ++i) {
        if (mid >= P[i]) {
          can.push_back(std::min((mid - P[i]) / S[i], 1LL * M[i]));
        }
      }
      std::sort(can.begin(), can.end());
      std::reverse(can.begin(), can.end());
      LL tot = 0;
      for (int i = 0; i < R; ++i) {
        if (i >= can.size()) break;
        tot += can[i];
      }
      if (tot >= B) hi = mid;
      else lo = mid;
    }
    std::cout << hi << std::endl;
  }

  return 0;
}
