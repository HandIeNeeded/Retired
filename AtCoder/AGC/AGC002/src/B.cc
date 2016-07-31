/*************************************************************************
  >         File: B.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 08:11:45 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
int cnt[N];

int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cnt[i] = 1;
  set<int> s;
  s.insert(1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (s.count(x)) {
      s.insert(y);
    }
    cnt[x]--, cnt[y]++;
    if (cnt[x] == 0) {
      s.erase(x);
    }
  }
  cout << s.size() << endl;


  return 0;
}
