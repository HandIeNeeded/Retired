/*************************************************************************
  >         File: D.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 21 Aug 2016 09:00:08 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
const int N = 1e5 + 5;
int visited[N], p[N], tot;

void Prime() {
  for (int i = 2; i < N; i++) {
    if (!visited[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      visited[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
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
  static int length = 0, bit[20];
  for (; x > 0; x /= 10) bit[length++] = x % 10;
  if (!length) bit[length++] = 0;
  while (length--) putchar(bit[length] + '0');
  putchar('\n');
}

std::vector<LL> numbers;
std::map<LL, LL> match;

inline int Count(LL x) {
  return std::upper_bound(numbers.begin(), numbers.end(), x) - std::lower_bound(numbers.begin(), numbers.end(), x);
}

int main() {
  Prime();
  int n;
  in(n);
  int zero = 0;
  for (int i = 0; i < n; i++) {
    LL x;
    in(x);
    LL now = 1, pair = 1;
    for (int j = 0; j < tot && 1LL * p[j] * p[j] * p[j] <= x; j++) if (x % p[j] == 0) {
      int cnt = 0;
      while (x % p[j] == 0) {
        x /= p[j];
        cnt++;
      }
      cnt %= 3;
      for (int i = 0; i < cnt; i++) now *= p[j];
      for (int i = 0; i < (3 - cnt) % 3; i++) pair *= p[j];
    }
    if (x == 1 && now == 1) {
      zero++;
    } else if (x == 1) {
      numbers.emplace_back(now);
      match[now] = pair;
    } else if (x != 1) {
      int rt = sqrt(x + 0.5);
      if (1LL * rt * rt == x) {
        now *= x;
        pair *= rt;
      } else {
        if (x >= N) continue;
        now *= x;
        pair *= x * x;
      }
      numbers.emplace_back(now);
      match[now] = pair;
    }
  }
  std::sort(numbers.begin(), numbers.end());
  int nouse = 0;
  for (auto it = numbers.begin(); it != numbers.end(); ) {
    auto number = *it;
    nouse += std::min(Count(number), Count(match[number]));
    it = std::upper_bound(numbers.begin(), numbers.end(), number);
  }
  out(n - zero - nouse / 2 + (zero > 0));
  return 0;
}
