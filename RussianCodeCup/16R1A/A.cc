/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 09 May 2016 12:02:14 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int a[4];
const int N = 25;
bool dp[N][N][N][N][2], pre[N][N][N][N][2];

void dfs(int a, int b, int c, int d) {
  REP(i, 2) {
    if (dp[a][b][c][d][i]) {
      if (i == 0 && a + 1 <= 20 && !dp[a + 1][b][c][d][0]) {
        dp[a + 1][b][c][d][0] = 1;
        pre[a + 1][b][c][d][0] = 0;
        dfs(a + 1, b, c, d);
      }
      if (i == 0 && b + 1 <= 20 && !dp[a][b + 1][c][d][1]) {
        dp[a][b + 1][c][d][1] = 1;
        pre[a][b + 1][c][d][1] = 0;
        dfs(a, b + 1, c, d);
      }
      if (i == 1 && c + 1 <= 20 && !dp[a][b][c + 1][d][0]) {
        dp[a][b][c + 1][d][0] = 1;
        pre[a][b][c + 1][d][0] = 1;
        dfs(a, b, c + 1, d);
      }
      if (i == 1 && d + 1 <= 20 && !dp[a][b][c][d + 1][1]) {
        dp[a][b][c][d + 1][1] = 1;
        pre[a][b][c][d + 1][1] = 1;
        dfs(a, b, c, d + 1);
      }
    }
  }
}

void Init() {
  REP(i, 2) dp[0][0][0][0][i] = 1;
  dfs(0, 0, 0, 0);
}

void print(int index) {
  string ans;
  int n = 1;
  REP(i, 4) n += a[i];
  REP(i, n) {
    ans += '0' + index;
    int p = pre[a[0]][a[1]][a[2]][a[3]][index];
    if (p == 0 && index == 0) a[0]--;
    if (p == 0 && index == 1) a[1]--;
    if (p == 1 && index == 0) a[2]--;
    if (p == 1 && index == 1) a[3]--;
    index = p;
  }
  reverse(ans.begin(), ans.end());
  puts(ans.c_str());
}

int main() {
#ifdef HOME
    std::string file(__FILE__);
    freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

  int t;
  Init();
  scanf("%d", &t);
  while (t--) {
    REP(i, 4) scanf("%d", a + i);
    int find = 0;
    REP(i, 2) {
      if (dp[a[0]][a[1]][a[2]][a[3]][i]) {
        find = 1;
        print(i);
        break;
      }
    }
    if (!find) puts("impossible");
  }
  return 0;
}



