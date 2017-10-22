/*************************************************************************
  >         File: C.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sat May 13 18:55:39 2017
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

int main() {
  std::ios::sync_with_stdio(0);
  std::string s[2];
  for (int i = 0; i < 2; ++i) std::cin >> s[i];
  int n = s[0].size();
  for (int i = 0; i < 2; ++i) std::sort(s[i].begin(), s[i].end());
  std::reverse(s[1].begin(), s[1].end());
  int R = n - 1;
  std::string answer;
  int start = -1;
  for (int i = 0; i < n; ++i) {
    int idx = i / 2;
    char a = s[0][idx + (i & 1)];
    char b = s[1][idx];
    if (a < b) answer += (i & 1 ? b : a);
    else {
      start = i;
      break;
    }
  }
  if (start < 0) {
    std::cout << answer << std::endl;
    return 0;
  }
  std::string A, B;
  std::vector<int> posA, posB;
  for (int j = start; j < n; ++j) {
    int idx = j / 2;
    char a = s[0][idx + (j & 1)];
    char b = s[1][idx];
    if (j & 1) B += b, posB.emplace_back(R--);
    else A += a, posA.emplace_back(R--);
  }
  std::reverse(posA.begin(), posA.end());
  std::reverse(posB.begin(), posB.end());
  answer.resize(n);
  int now = 0;
  for (auto &x: posA) {
    answer[x] = A[now++];
  }
  now = 0;
  for (auto &y: posB) {
    answer[y] = B[now++];
  }
  std::cout << answer << std::endl;

  return 0;
}
