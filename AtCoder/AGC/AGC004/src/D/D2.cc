/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 04 Sep 2016 08:35:41 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
int next[N];
int n, k;
std::vector<int> edges[N];

int Dfs(int x, int &answer) {
  int mx = -1;
  for (auto &y: edges[x]) if (y != 1) {
    int dep = Dfs(y, answer);
    if (dep == k - 1 && x != 1) answer++;
    else mx = std::max(mx, dep);
  }
  return mx + 1;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) std::cin >> next[i], edges[next[i]].push_back(i);
  int answer = 0;
  if (next[1] != 1) {
    answer++;
    edges[next[1]].erase(std::find(edges[next[1]].begin(), edges[next[1]].end(), 1));
    next[1] = 1;
  }
  Dfs(1, answer);
  std::cout << answer << std::endl;
  return 0;
}
