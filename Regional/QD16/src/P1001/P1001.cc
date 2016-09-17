/*************************************************************************
  >         File: P1001.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 12:13:49 PM CST
*************************************************************************/
#include <bits/stdc++.h>
int factor[] = {2, 3, 5, 7};
std::vector<long long> numbers;

void Dfs(long long x, int dep) {
  if (x > int(2e9)) return ;
  if (dep == 4) numbers.emplace_back(x);
  else {
    Dfs(x, dep + 1);
    for (int i = 0; i < 31; ++i) {
      x *= factor[dep];
      Dfs(x, dep + 1);
    }
  }
}

int main() {
  Dfs(1, 0);
  std::sort(numbers.begin(), numbers.end());
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", *std::lower_bound(numbers.begin(), numbers.end(), n));
  }
  return 0;
}
