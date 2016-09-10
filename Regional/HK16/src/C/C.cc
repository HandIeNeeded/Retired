/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 10 Sep 2016 04:46:14 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 4e5 + 5;
std::pair<int, int> p[N];

int mx[N << 2], flag[N << 2];
int qx, qd = 1, ql, qr;

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID 
#define RC R, MID + 1, r

void push(int x, int l, int r) {
  flag[L] += flag[x], flag[R] += flag[x];
  mx[L] += flag[x], mx[R] += flag[x];
  flag[x] = 0;
}

void update(int x, int l, int r) {
  if (ql <= l && qr >= r) {
    mx[x] += qd;
    flag[x] += qd;
  }
  else {
    if (flag[x]) push(x, l, r);
    if (ql <= MID) update(LC);
    if (qr > MID) update(RC);
    mx[x] = std::max(mx[L], mx[R]);
  }
}

int query(int x, int l, int r) {
  if (ql <= l && qr >= r) return mx[x];
  else {
    if (flag[x]) push(x, l, r);
    int a = 0, b = 0;
    if (ql <= MID) a = query(LC);
    if (qr > MID) b = query(RC);
    return std::max(a, b);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> numbers;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    p[i] = {x, y};
    numbers.emplace_back(x);
    numbers.emplace_back(y);
  }
  std::sort(numbers.begin(), numbers.end());
  numbers.resize(std::unique(numbers.begin(), numbers.end()) - numbers.begin());
  int tot = numbers.size();
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::tie(x, y) = p[i];
    x = std::lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin() + 1;
    y = std::lower_bound(numbers.begin(), numbers.end(), y) - numbers.begin() + 1;
    p[i] = {x, y};
  }
  sort(p, p + n, [] (std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second || (a.second == b.second && a.first > b.first);
  });

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    std::tie(ql, qr) = p[i];
    if (query(1, 1, tot) < k) {
      ans++;
      update(1, 1, tot);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
