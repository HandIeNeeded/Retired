/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue Dec  6 23:47:29 2016
*************************************************************************/
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
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

const int N = 111;
int a[N], b[N], vis[N];

int Lcm(int x, int y) {
  return x * y / std::__gcd(x, y);
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    b[a[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) if (!b[i]) {
    std::cout << -1 << std::endl;
    return 0;
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    if (!vis[x]) {
      int cnt = 0;
      while (!vis[x]) {
        cnt++;
        vis[x] = 1;
        x = a[x];
      }
      if (cnt % 2 == 0) cnt >>= 1;
      ans = Lcm(ans, cnt);
    }
  }
  std::cout << ans << std::endl;

  return 0;
}
