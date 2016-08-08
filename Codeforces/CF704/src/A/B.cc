/*************************************************************************
  >         File: B.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 07 Aug 2016 11:35:34 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 5555;
int a[N], b[N], c[N], d[N], x[N];

LL f(int i, int j) {
  return 1LL * abs(x[i] - x[j]) + (j < i ? c[i] + b[j] : a[j] + d[i]);
}

int main() {
  ios::sync_with_stdio(0);
  
  int n, st, en;
  cin >> n >> st >> en;
  st--, en--;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  vector<int> nodes;
  nodes.push_back(st), nodes.push_back(en);
  LL ans = f(st, en) + f(en, st);
  for (int i = 0; i < n; i++) if (i != st && i != en) {
    LL mi = LLONG_MAX;
    int idx = -1;
    //cout << "hehe" << endl;
    for (int j = 0; j < nodes.size() - 1; j++) {
      LL res = ans;
      res -= f(nodes[j], nodes[(j + 1)]);
      res += f(nodes[j], i) + f(i, nodes[(j + 1)]);
      if (res < mi) {
        mi = res;
        idx = j;
      }
    }
    nodes.insert(nodes.begin() + idx + 1, i);
    ans = mi;
    //for (auto &x: nodes) {
    //  cout << x << ' ';
    //}
    //cout << "**************************" << endl;
  }
  //for (auto &x: nodes) {
  //  cout << x << ' ';
  //}
  //cout << "**************************" << endl;
  cout << ans - f(en, st) << endl;

  return 0;
}
