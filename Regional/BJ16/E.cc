/*************************************************************************
  >         File: E.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 24 Sep 2016 12:31:18 PM CST
*************************************************************************/
#include <bits/stdc++.h>

constexpr int N = 1e5 + 5;
int id[N];
std::vector<int> edges[N];

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) > 0) {
    std::map<std::string, int> nameMap;
    int now = 0;
    for (int i = 0; i < n; ++i) {
      static char s[20];
      scanf("%s", s);
      if (!nameMap.count(s)) {
        nameMap[s] = ++now;
      }
      id[i + 1] = now;
    }
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      edges[x].push_back(y);
      edges[y].push_back(x);
    }
    int total = nameMap.size();
    assert(total < 1000);
    for (int i = 1; i <= total; ++i) {

    }
  }


  return 0;
}
