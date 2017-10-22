/*************************************************************************
  >         File: B.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Tue 21 Feb 2017 01:12:21 AM JST
*************************************************************************/
#include <bits/stdc++.h>

using LL = long long;

std::map<LL, LL> map;

LL get(LL x) {
  if (x <= 1) return 1;
  else if (map[x]) return map[x];
  else return map[x] = get(x / 2) * 2 + 1;
}

LL dfs(LL x, LL l, LL r) {
  if (l > r) return 0;
  if (x <= 1) return x;
  LL half = get(x / 2);
  LL ans = 0;
  if (r <= half) return dfs(x / 2, l, r);
  else if (l > half + 1) return dfs(x / 2, l - half - 1, r - half - 1);
  else {
    if (l <= half + 1 && r >= half + 1) ans += x & 1;
    return ans + dfs(x / 2, l, half) + dfs(x / 2, 1, r - half - 1);
  }
  return 0;
}


int main() {
  std::ios::sync_with_stdio(0);
  LL n;
  LL l, r;
  std::cin >> n >> l >> r;
  LL ans = dfs(n, l, r);
  std::cout << ans << std::endl;

  return 0;
}
