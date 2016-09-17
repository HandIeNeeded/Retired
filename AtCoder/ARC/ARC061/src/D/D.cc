/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 12 Sep 2016 11:27:41 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::set<std::pair<int, int>> rectangles[10];
  int H, W, n;
  std::cin >> H >> W >> n;
  std::set<std::pair<int, int>> points;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    points.emplace(x, y);
  }
  for (auto &point: points) {
    int x, y;
    std::tie(x, y) = point;
    for (int dx = 0; dx < 3; ++dx) {
      for (int dy = 0; dy < 3; ++dy) {
        int tx = x - dx, ty = y - dy;
        if (tx < 1 || ty < 1) continue;
        if (tx + 2 > H || ty + 2 > W) continue;
        int cnt = 0;
        for (int a = 0; a < 3; ++a) {
          for (int b = 0; b < 3; ++b) {
            int bx = tx + a, by = ty + b;
            if (points.count({bx, by})) cnt++;
          }
        }
        rectangles[cnt].emplace(tx, ty);
      }
    }
  }
  using LL = long long;
  LL sum = 0;
  for_each(rectangles, rectangles + 10, [&sum] (auto rectangle) {
      sum += rectangle.size();
  });
  std::cout << 1LL * (H - 2) * (W - 2) - sum << std::endl;
  for (int i = 1; i < 10; ++i) std::cout << rectangles[i].size() << std::endl;

  return 0;
}
