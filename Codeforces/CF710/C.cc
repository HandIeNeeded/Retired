/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 22 Aug 2016 10:59:47 PM CST
*************************************************************************/
#include <bits/stdc++.h>

int mp[50][50];

void Dfs(int x, int y, int n) {
  if (n <= 2) {
    if (n == 1) mp[x][y] = 1;
    else {
      mp[x][y] = 1, mp[x][y + 1] = 2;
      mp[x + 1][y] = 3, mp[x + 1][y + 1] = 4;
    }
  } else {
    int left = x, right = x + n - 1;
    int up = y, down = y + n - 1;
    auto odd = n * n, even = odd - 1;
    mp[left][up] = even; even -= 2;
    mp[left][down] = even; even -= 2;
    mp[right][up] = even; even -= 2;
    mp[right][down] = even; even -= 2;
    for (int i = up + 1; i <= down - 1; i++) {
      mp[i][left] = odd; odd -= 2;
      mp[i][right] = odd; odd -= 2;
    }
    for (int i = left + 1; i <= right - 2; i++) {
      mp[up][i] = even; even -= 2;
      mp[down][i] = even; even -= 2;
    }
    mp[up][right - 1] = odd; odd -= 2;
    mp[down][right - 1] = odd; odd -= 2;
    Dfs(x + 1, y + 1, n - 2);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  Dfs(0, 0, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << mp[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
