/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 15 Oct 2016 08:29:45 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;
constexpr int N = 444;
std::vector<int> color[N];
std::map<std::vector<int>, int> has;
int corner[8];
int use[4][4] = {
  {0, 3, 6, 5},
  {0, 5, 4, 1},
  {1, 4, 7, 2},
  {2, 7, 6, 3}
};

void Add(std::vector<int> color) {
  for (int i = 0; i < 4; ++i) {
    has[color]++;
    std::rotate(color.begin(), color.begin() + 1, color.end());
  }
}

void Hide(std::vector<int> color) {
  for (int i = 0; i < 4; ++i) {
    has[color]--;
    std::rotate(color.begin(), color.begin() + 1, color.end());
  }
}

void Dfs(int dep, LL& ans, LL res = 1) {
  if (dep == 4) ans += res;
  else {
    std::vector<int> tmp(4);
    for (int i = 0; i < 4; ++i) tmp[i] = corner[use[dep][i]];
    if (has.count(tmp)) {
      int cnt = has[tmp];
      Hide(tmp);
      Dfs(dep + 1, ans, res * cnt);
      Add(tmp);
    }
  }
}

LL solve(int a, int b) {
  for (int i = 0; i < 4; ++i) {
    corner[i] = color[a][i];
    corner[i + 4] = color[b][i];
  }
  LL ans = 0;
  for (int i = 0; i < 4; ++i) {
    Dfs(0, ans);
    std::rotate(corner + 4, corner + 5, corner + 8);
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    color[i].resize(4);
    for (int j = 0; j < 4; ++j) {
      std::cin >> color[i][j];
    }
    Add(color[i]);
  }
  LL answer = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      Hide(color[i]), Hide(color[j]);
      answer += solve(i, j);
      Add(color[i]), Add(color[j]);
      //std::cerr << "# i << ' ' << j << ' ' << answer # is " << i << ' ' << j << ' ' << answer << std::endl;
    }
    Hide(color[i]);
  }
  std::cout << answer << std::endl;
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
