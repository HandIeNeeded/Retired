/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat Apr  8 18:48:25 2017
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

constexpr int N = 200;
char mp[N][N];

int main() {
  std::ios::sync_with_stdio(0);
  int T;
  std::cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mp[i][j] = '.';
    int score = 0;
    auto get = [] (char c) {
      if (c == 'o') return 2;
      if (c == '+' || c == 'x') return 1;
      return 0;
    };
    for (int i = 0; i < m; ++i) {
      char c;
      int x, y;
      std::cin >> c >> x >> y;
      --x, --y;
      mp[x][y] = c;
      score += get(c);
    }
    int add = 0;
    std::vector<std::tuple<char, int, int>>  answer;
    for (int i = 0; i < n - 1; ++i) {
      if (mp[0][i] != '+') {
        score -= get(mp[0][i]);
        ++score;
        ++add;
        answer.emplace_back('+', 0, i);
      }
    }
    if (mp[0][n - 1] != 'o') {
      score -= get(mp[0][n - 1]);
      score += 2;
      ++add;
      answer.emplace_back('o', 0, n - 1);
    }
    for (int i = 0; i < n - 1; ++i) {
      ++add;
      answer.emplace_back('x', i + 1, n - 2 - i);
      ++score;
    }
    for (int i = 0; i < n - 2; ++i) {
      ++add;
      answer.emplace_back('+', n - 1, i + 1);
      ++score;
    }
    if (n > 2) assert(score == 3 * n - 2);
    else assert(score == 2 * n);
    std::cout << "Case #" << cas << ": " << score << ' ' << add << std::endl;
    for(auto &p: answer) {
      char c;
      int x, y;
      std::tie(c, x, y) = p;
      std::cout << c << ' ' << x + 1 << ' ' << y + 1 << std::endl;
    }
  }

  return 0;
}
