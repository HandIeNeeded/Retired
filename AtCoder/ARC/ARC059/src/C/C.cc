/*************************************************************************
  >         File: C.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 13 Aug 2016 08:01:17 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> numbers;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    numbers.push_back(x);
  }
  int res = INT_MAX;
  for (int i = -100; i <= 100; i++) {
    int ans = 0;
    for (auto &x: numbers) {
      ans += (x - i) * (x - i);
    }
    res = min(res, ans);
  }
  cout << res << endl;


  return 0;
}
