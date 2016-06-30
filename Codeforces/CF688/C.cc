/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 30 Jun 2016 01:20:08 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
int color[N];
vector<int> edge[N];

bool dfs(int x) {
  //cout << x << endl;
  for (auto &y: edge[x]) {
    if (color[y]) {
      if (color[y] + color[x] != 3) return 0;
    }
    else {
      color[y] = 3 - color[x];
      if (!dfs(y)) return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  REP(i, m) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  int good = 1;
  REPP(i, 1, n) if (!color[i]) {
    color[i] = 1;
    good &= dfs(i);
    //cout << "Good: " << good << endl;
  }
  if (good) {
    int cnt = 0;
    REPP(i, 1, n) if (color[i] == 1) cnt++;
    cout << cnt << endl;
    REPP(i, 1, n) if (color[i] == 1) {
      cout << i << ' ';
    }
    cout << endl;
    cout << n - cnt << endl;
    REPP(i, 1, n) if (color[i] != 1) {
      cout << i << ' ';
    }
    cout << endl;
  }
  else {
    cout << "-1" << endl;
  }

  return 0;
}


