/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 08 Jul 2016 02:53:52 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

bool good(int x, int y) {
  if (x == 3 && y == 1) return 1;
  return x >= 0 && x < 3 && y >= 0 && y < 3;
}

pair<int, int> Get(int a) {
  if (a == -1) return {3, 1};
  return make_pair(a / 3, a % 3);
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  string str;
  cin >> n >> str;
  vector<pair<int, int>> dx;
  REP(i, n - 1) {
    int a = str[i] - '1';
    int b = str[i + 1] - '1';
    int x, y, tx, ty;
    tie(x, y) = Get(a), tie(tx, ty) = Get(b);
    dx.push_back({tx - x, ty - y});
  }
  REP(i, 4) {
    REP(j, 3) {
      int x = i, y = j;
      if (!good(i, j)) continue;
      int ta, tb;
      tie(ta, tb) = Get(str[0] - '1');
      if (ta == x && tb == y) continue;
      int bad = 0;
      for (auto &p: dx) {
        int tx = x + p.first, ty = y + p.second;
        if (good(tx, ty)) {
          x = tx, y = ty;
          continue;
        }
        else {
          bad = 1;
          break;
        }
      }
      if (!bad) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;

  return 0;
}

