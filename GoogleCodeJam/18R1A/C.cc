/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@fb.com
  > Created Time: Sat 14 Apr 04:18:07 2018
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

const int N = 111;
int W[N], H[N];

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    int n, P;
    std::cin >> n >> P;
    for (int i = 0; i < n; ++i) {
      std::cin >> W[i] >> H[i];
    }
    double sum = 2 * (W[0] + H[0]) * n;
    P -= sum;
    double mi = 2 * std::min(W[0], H[0]);
    double mx = 2 * std::sqrt(1.0 * W[0] * W[0] + 1.0 * H[0] * H[0]);
    double ans = 0;
    for (int i = 0; i <= n; ++i) {
      if (i * mi <= P) {
        ans = std::max(ans, std::min(1.0 * P, i * mx));
      }
    }
    mx = std::min(mx, 1.0 * P);
    std::cout << "Case #" << cas + 1 << ": ";
    std::cout << std::fixed << std::setprecision(10) << sum + ans << std::endl;
  }


  return 0;
}
