/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 21 May 2016 11:26:15 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 70;
const int MO = 1e9 + 7;
int dp[N][2], bit[N];
bool vis[N][2];

void dfs(int dep, int flag) {
  if (dep == 0) {
    REP(i, 2) dp[dep][i] = i;
    return ;
  }

}

int solve(LL n) {
  int length = 0;
  while (n) {
    bit[length++] = n & 1;
    n >>= 1;
  }
  dfs(length - 1, 0);
  return (dp[length
}

int main() {
  LL n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}



