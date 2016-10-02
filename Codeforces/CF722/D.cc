/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 10:37:37 PM CST
*************************************************************************/
#include <bits/stdc++.h>
const int N = 111111;
int a[N], n;
std::set<int> has;
std::map<int, int> mp;

bool check(int bound) {
  //std::cerr << "# bound # is " << bound << std::endl;
  has.clear();
  has.insert(a, a + n);
  for (int i = n - 1; i >= 0; --i) {
    int x = a[i];
    std::vector<int> paths;
    while (x) paths.emplace_back(x), x /= 2;
    int find = 0;
    for (auto &num: paths) {
      if (num <= bound && !has.count(num)) {
        has.erase(a[i]);
        has.insert(num);
        find = 1;
        break;
      }
    }
    if (!find && a[i] > bound) return false;
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a, a + n);
  int lo = n - 1, hi = 1e9;
  while (lo + 1 < hi) {
    int mid = (hi + lo) / 2;
    if (check(mid)) hi = mid;
    else lo = mid;
  }
  check(hi);
  for (auto &x: has) {
    std::cout << x << std::endl;
  }
  return 0;
}
