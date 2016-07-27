/*************************************************************************
  > File Name: flip-game.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Wed 27 Jul 2016 12:37:39 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int mp[55][55];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (mp[i][0] == 0) {
      for (int j = 0; j < m; j++) {
        mp[i][j] ^= 1;
      }
    }
  }
  LL sum = 0;
  for (int i = 0, j = m - 1; i < m; i++, j--) {
    int cnt = 0;
    for (int k = 0; k < n; k++) {
      if (mp[k][i] == 1) cnt++;
    }
    cnt = max(cnt, n - cnt);
    sum += (1LL << j) * cnt;
  }
  cout << sum << endl;


  return 0;
}
