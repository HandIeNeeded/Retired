/*************************************************************************
  >         File: E.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 02 Sep 2016 07:59:53 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
 
int main() {
  std::vector<LL> stack;
  int n, m;
  scanf("%d%d", &n, &m);
  stack.emplace_back(n);
  for (int i = 0; i < m; i++) {
    LL x;
    scanf("%lld", &x);
    while (stack.size() && stack.back() >= x) stack.pop_back();
    stack.emplace_back(x);
  }
  std::map<LL, LL> positions;
  positions.insert({stack.back(), 1});
  while (stack.size()) {
    LL position = stack.back(); stack.pop_back();
    auto pos = positions.upper_bound(position);
    for(auto itr = pos; itr != positions.end(); itr = positions.erase(itr)) {
      LL x, y;
      std::tie(x, y) = *itr;
      LL k = x / position, b = x % position;
      positions[position] += y * k;
      positions[b] += y;
    }
  }
  LL now = 0;
  std::vector<LL> answer(n, 0);
  for (int i = n; i >= 1; i--) {
    now += positions[i];
    answer[i - 1] = now;
  }
  for (auto x: answer) {
    printf("%lld\n", x);
  }
  return 0;
}
