/*************************************************************************
  > File Name: A.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Sat 16 Jul 2016 08:01:00 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < 2 * n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[2 * i];
  }
  cout << ans << endl;


  return 0;
}
