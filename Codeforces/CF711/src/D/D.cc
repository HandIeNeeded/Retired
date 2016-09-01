/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 29 Aug 2016 08:10:18 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 2e5 + 5;
const int MO = 1e9 + 7;
int next[N], mark[N];

int Powd(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1LL * ans * x % MO;
    x = 1LL * x * x % MO;
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> next[i];
  int answer = 1;
  int free = n;
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      int node = i;
      while (!mark[node]) {
        mark[node] = i;
        node = next[node];
      }
      if (mark[node] != i) continue;
      int cnt = 0;
      while (mark[node] != n + i) {
        mark[node] = n + i;
        node = next[node];
        cnt++;
      }
      free -= cnt;
      answer = 2LL * answer * (Powd(2, cnt - 1) - 1) % MO;
    }
  }
  assert(free >= 0);
  answer = 1LL * answer * Powd(2, free) % MO;
  std::cout << answer << std::endl;
  return 0;
}
