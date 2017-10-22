/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun Jan 15 20:32:06 2017
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

constexpr int MO = 1e9 + 7;

int inv(int x) {
  if (x <= 1) return x;
  return MO - 1LL * MO / x * inv(MO % x) % MO;
}

int main() {
  std::ios::sync_with_stdio(0);
  #ifdef HOME
  freopen("D.in", "r", stdin);
  //freopen("D.out", "w", stdout);
  #endif
  int t, cas = 0;
  std::cin >> t;
  constexpr int N = 2222;
  for (int i = 0; i < t; ++i) {
    static int r[N];
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> r[i];
    int ans = 0;
    if (n == 1) {
      ans = m;
    } else {
      int sum = std::accumulate(r, r + n, 0);
      auto add = [] (int &a, int  b) {
        a += b; if (a >= MO) a -= MO;
      };
      static int cnt[N << 1];
      static int fac[N];
      fac[0] = 1;
      for (int i = 1; i <= N - 1; ++i) fac[i] = 1LL * fac[i - 1] * i % MO;
      memset(cnt, 0, sizeof(cnt));
      for (int L = 0; L < n; ++L) {
        for (int R = 0; R < n; ++R) if (L - R) {
          //L be the leftmost position, R be the rightmost
          // for a certain range, we have bijection: m - 1 - 2 * sum + r[L] + r[R] = x_1 + ... + x_{n - 2} + x_{n - 1} + x_{n} + x_{n + 1}
          // answer = C(X, n);
          cnt[r[L] + r[R]]++;
        }
      }
      int now = 1, up, down;
      int first = 0;
      for (int i = 0; i < 2 * N; ++i) {
        up = m - 1 - 2 * sum + i + n;
        down = n;
        if (up < down) continue;
        //up >= down
        if (!first) {
          first = 1;
          for (int j = 0; j < n; ++j) {
            now = 1LL * now * up-- % MO;
            now = 1LL * now * inv(down--) % MO;
          }
        } else {
          now = 1LL * now * up % MO;
          now = 1LL * now * inv(up - down) % MO;
        }
        //std::cerr << "# now # is " << now << std::endl;
        add(ans, 1LL * cnt[i] * now % MO);
      }
      ans = 1LL * ans * fac[n - 2] % MO;
    }
    std::cout << "Case #" << ++cas << ":";
    std::cout << " " << ans << std::endl;
  }


  return 0;
}
