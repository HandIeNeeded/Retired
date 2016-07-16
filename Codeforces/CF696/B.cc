/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 15 Jul 2016 12:54:41 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
vector<int> edge[N];
int son[N];
double answer[N], add[N];

void Dfs(int x, int p) {
  for (auto &y: edge[x]) if (y != p) {
    Dfs(y, x);
    son[x] += son[y];
  }
  son[x]++;
}

void Dfs2(int x, int p) {
  for (auto &y: edge[x]) if (y != p) {
    Dfs2(y, x);
  }
  for (auto &y: edge[x]) if (y != p) {
    add[y] += 0.5 * (son[x] - 1 - son[y]);
  }
  add[x] += 1.0;
}

void Dfs3(int x, int p, double now) {
  answer[x] = now + add[x];
  for (auto &y: edge[x]) if (y != p) {
    Dfs3(y, x, now + add[x]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  REP(i, n - 1) {
    int x;
    cin >> x;
    edge[x].push_back(i + 2);
    edge[i + 2].push_back(x);
  }
  Dfs(1, 0);
  Dfs2(1, 0);
  Dfs3(1, 0, 0);
  REPP(i, 1, n) {
    cout << fixed << setprecision(10) << answer[i] << ' ';
  }
  cout << endl;
  return 0;
}


