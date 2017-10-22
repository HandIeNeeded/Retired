/*************************************************************************
  >         File: B_mst.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 22 Oct 2017 03:48:38 PM JST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 111;
int parent[N];
std::pair<int, int> p[N];

int get(int x) { return parent[x] == x ? x : parent[x] = get(parent[x]);}

int main() {
  std::ios::sync_with_stdio(0);
  int t, cas = 1;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cin >> p[i].first;
    }
    for (int i = 0; i < n; ++i) {
      std::cin >> p[i].second;
      parent[i] = i;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int value = std::min(p[i].first ^ p[j].second, p[i].second ^ p[j].first);
        edges.push_back({value, {i, j}});
      }
    }
    sort(edges.begin(), edges.end(), [] (auto a, auto b) {
          return a.first < b.first;
        });
    using LL = long long;
    LL ans = 0;
    for (auto &edge: edges) {
      int v, x, y;
      v = edge.first;
      x = edge.second.first;
      y = edge.second.second;
      if (get(x) != get(y)) {
        parent[get(x)] = get(y);
        ans += v;
        n--;
        if (n == 1) break;
      }
    }
    std::cout << "Case #" << cas++ << ": " << ans << std::endl;
  }

  return 0;
}
