/*************************************************************************
  >         File: F.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 01 Oct 2016 11:49:08 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 44;
const int M = 1e5 + 5;
int gcd[N][N], a[M], cnt[M];
std::vector<int> arrays[M];
std::vector<std::pair<int, int>> positions[M];
int answer[M], reminder[N];
std::deque<int> mod[N][N];

inline bool check(int a, int k, int b, int m) {
  return (a - b) % gcd[k][m] == 0;
}

int get(const std::vector<int> &positions, const std::vector<int> &sizes) {
  if (positions.size() <= 1) return positions.size();
  int ans = 0;
  std::fill(reminder, reminder + N, -1);
  for (int i = 1; i <= 40; ++i) {
    for (int j = 0; j < i; ++j) mod[i][j].clear();
  }
  for (int i = 0; i < (int) positions.size(); ++i) {
    int size = sizes[i];
    int mod = positions[i];
    int maxIndex = -1;
    for (int i = 1; i <= 40; ++i) if (reminder[i] != -1) {
      if (check(reminder[i], i, mod, size)) continue;
      maxIndex = std::max(maxIndex, ::mod[i][reminder[i]].back());
    }
    if (maxIndex >= 0) {
      for (int i = 1; i <= 40; ++i) if (reminder[i] != -1) {
        while (::mod[i][reminder[i]].size() && ::mod[i][reminder[i]].front() <= maxIndex) 
          ::mod[i][reminder[i]].pop_front();
        if (::mod[i][reminder[i]].size() == 0) reminder[i] = -1;
      }
    }
    int min = M;
    for (int i = 1; i <= 40; ++i) if (reminder[i] != -1) {
      min = std::min(min, ::mod[i][reminder[i]].front());
    }
    reminder[size] = mod;
    ::mod[size][mod].emplace_back(i);
    ans = std::max(ans, std::max(1, i - min + 1));
  }
  return ans;
}

int solve(int x) {
  int ans = 0;
  //std::cerr << "# x # is " << x << std::endl;
  for (int i = 0; i < (int) positions[x].size(); ) {
    std::vector<int> tmp, cnt;
    tmp.emplace_back(positions[x][i].second);
    cnt.emplace_back(::cnt[positions[x][i].first]);
    int j = i + 1;
    while (j < (int) positions[x].size() && positions[x][j].first == positions[x][j - 1].first + 1) {
      tmp.push_back(positions[x][j].second);
      cnt.push_back(::cnt[positions[x][j].first]);
      j++;
    }
    i = j;
    ans = std::max(ans, get(tmp, cnt));
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
  int n, m;
  for (int i = 1; i <= 40; ++i) {
    for (int j = 1; j <= 40; ++j) {
      gcd[i][j] = std::__gcd(i, j);
    }
  }
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> cnt[i];
    for (int j = 0; j < cnt[i]; ++j) {
      int x;
      std::cin >> x;
      arrays[i].emplace_back(x);
      positions[x].push_back({i, j});
    }
  }
  for (int i = 1; i <= m; ++i) {
    answer[i] = solve(i);
  }
  for (int i = 1; i <= m; ++i) {
    std::cout << answer[i] << std::endl;
  }
  return 0;
}
