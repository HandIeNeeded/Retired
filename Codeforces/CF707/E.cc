/*************************************************************************
  >         File: E.cc
  >       Author: Riho.Yoshioka
  >         Nail: riho.yoshioka@yandex.com
  > Created Time: Sat 20 Aug 2016 10:24:48 PN CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
const int N = 2000 + 5;
std::vector<std::tuple<int, int, int>> ropes[N];
std::vector<std::tuple<int, int, int, int>> queries;
std::vector<int> has[N];
int on[N];
LL result[N], dp[N][N];

void updateY(int x, int y, int d) {
  for (; y < N; y += y & -y) dp[x][y] += d;
}

void updateX(int x, int y, int d) {
  for (; x < N; x += x & -x) updateY(x, y, d);
}

LL queryY(int x, int y) {
  LL answer = 0;
  for (; y; y -= y & -y) {
    answer += dp[x][y];
  }
  return answer;
}

LL queryX(int x, int y) {
  LL answer = 0;
  for (; x; x -= x & -x) {
    answer += queryY(x, y);
  }
  return answer;
}

LL Query(int x, int y, int z, int w) {
  return queryX(z, w) - queryX(z, y - 1) - queryX(x - 1, w) + queryX(x - 1, y - 1);
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int cnt;
    scanf("%d", &cnt);
    for (int j = 0; j < cnt; j++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      ropes[i].emplace_back(x, y, z);
    }
  }
  int q;
  scanf("%d", &q);
  std::fill(on, on + k, 1);
  for (int i = 0; i < q; i++) {
    static char type[10];
    scanf("%s", type);
    if (type[0] == 'S') {
      int x;
      scanf("%d", &x);
      on[--x] ^= 1;
    } else {
      int x, y, z, w;
      scanf("%d%d%d%d", &x, &y, &z, &w);
      for (int i = 0; i < k; i++) if (on[i]) {
        has[i].emplace_back(queries.size());
      }
      queries.emplace_back(x, y, z, w);
    }
  }
  for (int i = 0; i < k; i++) {
    for (auto &node: ropes[i]) {
      int x, y, z;
      std::tie(x, y, z) = node;
      updateX(x, y, z);
    }
    for (auto &idx: has[i]) {
      int x, y, z, w;
      std::tie(x, y, z, w) = queries[idx];
      result[idx] += Query(x, y, z, w);
    }
    for (auto &node: ropes[i]) {
      int x, y, z;
      std::tie(x, y, z) = node;
      updateX(x, y, -z);
    }
  }
  for (int i = 0; i < (int) queries.size(); i++) {
    std::cout << result[i] << std::endl;
  }
  return 0;
}
