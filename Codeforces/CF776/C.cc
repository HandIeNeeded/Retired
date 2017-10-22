/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Fri Feb 24 00:05:23 2017
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
using LL = long long;

const int N = 1e5 + 5;
LL sum[N];

int main() {
  std::ios::sync_with_stdio(0);
  LL n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    std::cin >> sum[i];
    sum[i] += sum[i - 1];
  }
  std::map<LL, int> cnt;
  cnt[0] = 1;
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    LL now = 1;
    if (k == 1) {
      LL need = sum[i] - now;
      ans += cnt[need];
    } else if (k == -1) {
      LL now = 1;
      for (int j = 0; j < 2; ++j) {
        LL need = sum[i] - now;
        ans += cnt[need];
        now *= k;
      }
    } else {
      do {
        LL need = sum[i] - now;
        ans += cnt[need];
        now *= k;
      } while (std::abs(now) < 1e16);
    }
    cnt[sum[i]]++;
  }
  std::cout << ans << std::endl;

  return 0;
}
