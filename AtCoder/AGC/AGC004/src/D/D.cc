/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 04 Sep 2016 08:35:41 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
int next[N], mark[N], dep[N], p[N][20];
std::vector<int> edges[N];

void DfsDep(int x, int p = 1, int dep = 0) {
  ::dep[x] = dep;
  ::p[x][0] = p;
  for (int i = 1; i < 20; i++) ::p[x][i] = ::p[::p[x][i - 1]][i - 1];
  for(auto &y: edges[x]) if (y != p) {
    DfsDep(y, x, dep + 1);
  }
}

int goStep(int x, int step) {
  for (int i = 0; i < 20; i++) {
    if (step & (1 << i)) x = p[x][i];
  }
  return x;
}

void goDown(int x) {
  if (mark[x]) return ;
  mark[x] = 1;
  for(auto &y: edges[x]) if (dep[y] > dep[x]) {
    goDown(y);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> next[i], edges[next[i]].push_back(i);
  int answer = 0;
  if (next[1] != 1) {
    answer++;
    edges[next[1]].erase(std::find(edges[next[1]].begin(), edges[next[1]].end(), 1));
    next[1] = 1;
  }
  DfsDep(1);
  std::priority_queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    q.emplace(dep[i], i);
  }
  while (!q.empty()) {
    int dis, x;
    std::tie(dis, x) = q.top(); q.pop();
    if (dis <= k) break;
    if (mark[x]) continue;
    else {
      int fa = goStep(x, k - 1);
      answer++;
      goDown(fa);
    }
  }
  std::cout << answer << std::endl;
  return 0;
}
