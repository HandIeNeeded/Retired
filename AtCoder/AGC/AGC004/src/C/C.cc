/*************************************************************************
  >         File: C.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 04 Sep 2016 09:09:32 PM CST
*************************************************************************/
#include <bits/stdc++.h>

char mp[2][555][555], g[555][555];

int main() {
  std::ios::sync_with_stdio(0);
  int h, w;
  std::cin >> h >> w;
  for (int i = 0; i < h; i++) {
    std::cin >> g[i];
  }
  memcpy(mp[0], g, sizeof(g));
  memcpy(mp[1], mp[0], sizeof(mp[0]));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g[i][j] == '#') mp[0][i][j] = mp[1][i][j] = '#';
    }
  }
  for (int i = 0; i < h; i++) mp[0][i][0] = '#', mp[1][i][w - 1] = '#';
  for (int i = 0; i < h; i++) {
    int x = i & 1;
    for (int j = 1; j < w - 1; j++) {
      mp[x][i][j] = '#';
    }
  }

  //answer
  for (int i = 0; i < h; i++) {
    std::cout << mp[0][i] << std::endl;
  }
  std::cout << std::endl;
  for (int i = 0; i < h; i++) {
    std::cout << mp[1][i] << std::endl;
  }
  return 0;
}
