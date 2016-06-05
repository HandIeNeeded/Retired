/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 09:08:43 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

char mp[4][4], graph[4][4];
int tmp[10];

pair<int, int> find(int x) {
  REP(i, 3) REP(j, 3) if (graph[i][j] == '0' + x) return {i, j};
  return {-1, -1};
}

bool check() {
  REP(i, 3) {
    REP(j, 3) {
      graph[i][j] = tmp[i * 3 + j] + '1';
      if (mp[i][j] != '?' && mp[i][j] != graph[i][j]) return 0;
    }
  }
  REPP(i, 1, 8) {
    int a, b;
    int c, d;
    tie(a, b) = find(i);
    tie(c, d) = find(i + 1);
    if (abs(a - c) + abs(b - d) != 1) return 0;
  }
  return 1;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  REP(i, 3) cin >> mp[i];
  REP(i, 9) tmp[i] = i;
  do {
    if (check()) {
      REP(i, 3) {
        REP(j, 3) {
          cout << char('1' + tmp[i * 3 + j]);
        }
        cout << endl;
      }
      break;
    }
  }while (next_permutation(tmp, tmp + 9));
  return 0;
}


