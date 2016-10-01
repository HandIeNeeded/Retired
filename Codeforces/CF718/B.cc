/*************************************************************************
  >         File: B.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Fri 23 Sep 2016 09:12:29 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
constexpr int N = 2e5 + 5;
int a[N], b[N], n, m;
LL answer[N], start[N];

void Init() {
  std::priority_queue<std::pair<LL, int>, std::vector<std::pair<LL, int>>, std::greater<std::pair<LL, int>>> q;
  q.emplace(0, 0);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::tie(x, y) = q.top(); q.pop();
    start[i] = x;
    q.emplace(x + a[y], y);
    if (i > 0) q.emplace(x + a[i], i);
  }
}

template<class T>
void Solve(T first, T last) {
  if (first == last) return ;
  LL bound = *std::max_element(b, b + m) * 1111LL;
  std::queue<std::tuple<LL, LL, T, T>> q;
  q.emplace(0, bound, first, last);
  while (!q.empty()) {
    T begin, end;
    LL x, y;
    std::tie(x, y, begin, end) = q.front(); q.pop();
    if (begin == end) continue;
    if (y - 1 == x) {
      for (auto itr = begin; itr != end; itr++) {
        answer[*itr] = y;
      }
      continue;
    }
    LL mid = x + (y - x) / 2;
    LL cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (start[i] <= mid) {
        cnt += (mid - start[i]) / a[i];
      }
    }
    auto bound = std::partition(begin, end, [&cnt] (auto idx) {
        return cnt >= b[idx];
        });
    q.emplace(x, mid, begin, bound);
    q.emplace(mid, y, bound, end);
  }
}

template<class T>
void in(T& x) {
  char c;
  while (!isdigit(c = getchar()) && c != '-');
  bool flag = (c == '-');
  if (flag) c = getchar();
  x = c - '0';
  while (isdigit(c = getchar())) x = x * 10 + c - '0';
  if (flag) x *= -1;
}

template<class T>
void out(T x) {
  if (x < 0) putchar('-'), x *= -1;
  int length = 0, bit[20];
  for (; x > 0; x /= 10) bit[length++] = x % 10;
  if (!length) bit[length++] = 0;
  while (length--) putchar(bit[length] + '0');
  putchar('\n');
}

int main() {
  std::cin >> n >> m;
  //for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) in(a[i]);
  std::sort(a, a + n);
  //for (int i = 0; i < m; ++i) std::cin >> b[i];
  for (int i = 0; i < m; ++i) in(b[i]);
  Init();
  //for (int i = 0; i < n; ++i) std::cerr << start[i] << std::endl;
  std::vector<int> indexs(m, 0);
  std::iota(indexs.begin(), indexs.end(), 0);
  Solve(indexs.begin(), indexs.end());
  //std::copy(answer, answer + m, std::ostream_iterator<int> (std::cout, "\n"));
  for (int i = 0; i < m; ++i) out(answer[i]);
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
