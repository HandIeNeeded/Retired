/*************************************************************************
  >         File: E.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 31 Jul 2016 09:31:02 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  set<int> s;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mx = max(x, mx);
  }
  n += mx;
  if (n & 1) {
    cout << "Second" << endl;
  }
  else {
    cout << "First" << endl;
  }

  return 0;
}
