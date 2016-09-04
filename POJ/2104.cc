/*************************************************************************
  >         File: 2104.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 04 Sep 2016 11:40:31 AM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 1e5 + 5;
int cnt[N], nowIdx;
std::pair<int, int> p[N];
int A[N], B[N], C[N], result[N], total, n, m;
std::vector<int> numbers;

void Add(int x) {
  for(; x <= total; x += x & -x) cnt[x] += 1;
}

int Ask(int x) {
  int answer = 0;
  for(; x; x -= x & -x) answer += cnt[x];
  return answer;
}

template<class T>
void Solve(T first, T last) {
  std::queue<std::tuple<int, int, T, T>> q;
  q.emplace(0, total, first, last);
  while (!q.empty()) {
    int L, R;
    T begin, end;
    std::tie(L, R, begin, end) = q.front(); q.pop();
    if (std::distance(begin, end) < 1) continue;
    if (R - 1 == L) {
      for_each(begin, end, [R] (int idx) {
          result[idx] = numbers[R] - 1e9 - 7;
          });
    } else {
      int mid = L + (R - L) / 2;
      if (mid < p[nowIdx].first) {
        nowIdx = 0;
        std::fill(cnt + 1, cnt + total + 1, 0);
      }
      for (int i = nowIdx + 1; i <= n && p[i].first <= mid; i++) {
        Add(p[i].second); nowIdx++;
      }
      auto bound = std::partition(begin, end, [] (int idx) {
          int cnt = Ask(B[idx]) - Ask(A[idx] - 1);
          return cnt >= C[idx];
          });
      q.emplace(L, mid, begin, bound);
      q.emplace(mid, R, bound, end);
    }
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
  int length = 0; 
  static int bit[20] = {0};
  for (; x > 0; x /= 10) bit[length++] = x % 10;
  if (!length) bit[length++] = 0;
  while (length--) putchar(bit[length] + '0');
  putchar('\n');
}

int main() {
  //std::ios::sync_with_stdio(0);
  //std::cin >> n >> m;
  //in(n), in(m);
  scanf("%d%d", &n, &m);
  numbers.emplace_back(0);
  for (int i = 1; i <= n; i++) {
    int x;
    //std::cin >> x;
    //in(x);
    scanf("%d", &x);
    p[i] = {x + 1e9 + 7, i};
    numbers.emplace_back(x + 1e9 + 7);
  }
  std::sort(numbers.begin(), numbers.end());
  numbers.resize(std::unique(numbers.begin(), numbers.end()) - numbers.begin());
  total = numbers.size() - 1;
  for (int i = 1; i <= n; i++) {
    p[i].first = std::lower_bound(numbers.begin(), numbers.end(), p[i].first) - numbers.begin();
  }
  sort(p + 1, p + n + 1);
  for (int i = 0; i < m; i++) {
    //std::cin >> A[i] >> B[i] >> C[i];
    //in(A[i]), in(B[i]), in(C[i]);
    scanf("%d%d%d", A + i, B + i, C + i);
  }
  std::vector<int> idx(m);
  std::iota(idx.begin(), idx.end(), 0);
  Solve(idx.begin(), idx.end());
  for (int i = 0; i < m; i++) {
    //std::cout << result[i] << std::endl;
    //out(result[i]);
    printf("%d\n", result[i]);
  }
  return 0;
}
