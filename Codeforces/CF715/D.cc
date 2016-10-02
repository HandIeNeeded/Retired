/*************************************************************************
  >         File: D.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 02 Oct 2016 11:46:05 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
int digits[100];
std::vector<std::tuple<int, int, int, int>> answers;
LL dp[100][100];

int main() {
  std::ios::sync_with_stdio(0);
  LL k;
  std::cin >> k;
  int length = 0;
  for (; length < 100 && k; ++length) {
    digits[length] = k % 3;
    k /= 3;
  }
  for (int i = 0; i < length; ++i) {
    std::cerr << digits[i] << ' ';
  }
  std::cerr << std::endl;

  for (int i = 0; i < 35; ++i) {
    answers.emplace_back(i + 1, i + 5, i + 1, i + 6);
    answers.emplace_back(i + 5, i + 1, i + 6, i + 1);
    answers.emplace_back(i + 1, i + 4, i + 2, i + 4);
    answers.emplace_back(i + 4, i + 1, i + 4, i + 2);
    if (digits[i] < 2) answers.emplace_back(i + 1, i + 3, i + 1, i + 4);
    if (digits[i] < 1) answers.emplace_back(i + 3, i + 1, i + 4, i + 1);
  }
  if (digits[35] < 2) answers.emplace_back(36, 38, 36, 39);
  if (digits[35] < 1) answers.emplace_back(38, 36, 39, 36);
  for (int i = 37; i <= 38; ++i) {
    if (digits[i - 1] < 2) answers.emplace_back(i, 39, i, 40);
    if (digits[i - 1] < 1) answers.emplace_back(39, i, 40, i);
  }
  answers.emplace_back(36, 39, 37, 39);
  answers.emplace_back(39, 36, 39, 37);
  answers.emplace_back(38, 39, 39, 39);
  answers.emplace_back(39, 38, 39, 39);

  assert(answers.size() <= 300);
  std::cout << 40 << ' ' << 40 << std::endl;
  std::cout << answers.size() << std::endl;
  for (auto &p: answers) {
    int a, b, c, d;
    std::tie(a, b, c, d) = p;
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
  }

  dp[1][1] = 1;
  for (int i = 2; i <= 40; ++i) {
    if (std::find(answers.begin(), answers.end(), std::make_tuple(1, i - 1, 1, i)) == answers.end()) dp[1][i] = dp[1][i - 1];
    if (std::find(answers.begin(), answers.end(), std::make_tuple(i - 1, 1, i, 1)) == answers.end()) dp[i][1] = dp[i - 1][1];
  }
  for (int i = 2; i <= 40; ++i) {
    for (int j = 2; j <= 40; ++j) {
      dp[i][j] = 0;
      if (std::find(answers.begin(), answers.end(), std::make_tuple(i - 1, j, i, j)) == answers.end()) dp[i][j] += dp[i - 1][j];
      if (std::find(answers.begin(), answers.end(), std::make_tuple(i, j - 1, i, j)) == answers.end()) dp[i][j] += dp[i][j - 1];
    }
  }
  std::cerr << "# dp[40][40] # is " << dp[40][40] << std::endl;
  std::cerr << "# answers.size() # is " << answers.size() << std::endl;
  return 0;
}
