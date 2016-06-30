/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 24 Jun 2016 01:11:20 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 3e5 + 5;
int son[N], pre[N], ans[N], size[N];
vector<int> edge[N];

void dfs(int x, int p) {
  for (auto &y: edge[x]) if (y != p) {
    pre[y] = x;
    dfs(y, x);
    son[x] += son[y];
  }
  son[x]++;
}

int halfSize;

bool good(int x, int a, int b) {
  int up = son[a] - son[x] + size[b];
  if (up > halfSize) return false;
  //TODO
  return true;
}

int CombineOneNode(int a, int b) {
  int idx = ans[a]; //larger tree's weight
  //size[a] >= size[b];
  halfSize = (size[a] + size[b]) / 2;
  while (!good(idx, a, b)) idx = pre[idx];
  return idx;
}

int CombineTwoTrees(int a, int b, int node) {
  int idx1 = ans[a], idx2 = ans[b];
  halfSize = (size[a] + size[b]) / 2;
  while (idx1 != node && !good(idx1, a, b)) idx1 = pre[idx1];
  if (idx1 != node) return idx1;
  while (idx2 != node && !good(idx2, a, b)) idx2 = pre[idx2];
  if (idx2 != node) return idx2;
  return node;
}

void Dfs(int x, int p) {
  ans[x] = x, size[x] = 1;
  //cout << x << endl;
  //cout << "***************************************" << x << endl;
  for (auto &y: edge[x]) if (y != p) Dfs(y, x);
  for (auto &y: edge[x]) if (y != p) {
    if (size[x] == 1) ans[x] = CombineOneNode(y, x);
    else ans[x] = CombineTwoTrees(y, x, x);
    size[x] += size[y];
    //cout << x << ' ' << size[x] << ' ' << ans[x] << endl;
  }
  //cout << "///////////////////////////////////////" << x << endl;
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  REP(i, n - 1) {
    int x;
    cin >> x;
    edge[x].push_back(i + 2);
    edge[i + 2].push_back(x);
  }
  dfs(1, 0);
  //REPP(i, 1, n) cout << i << ' ' << pre[i] << ' ' << son[i] << endl;
  Dfs(1, 0);
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << endl;
  }
  return 0;
}


