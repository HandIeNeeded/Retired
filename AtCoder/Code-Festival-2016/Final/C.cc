/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 27 Nov 2016 12:07:33 AM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 2e5 + 5;
std::vector<int> edges[N];
bool visited[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      int y;
      scanf("%d", &y);
      edges[i + 1].push_back(y + n);
      edges[y + n].push_back(i + 1);
    }
  }
  std::queue<int> q;
  q.push(1);
  visited[1] = 1;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for(auto &y: edges[x]) {
      if (!visited[y]) {
        visited[y] = 1;
        q.push(y);
      }
    }
  }
  for (int i = 1; i <= n; ++i) if (!visited[i]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
