/*************************************************************************
  > File Name: 3-divisible-pairs.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Wed 27 Jul 2016 12:27:34 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  int cnt[3] = {0};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x % 3]++;
  }
  cout << 1LL * cnt[1] * cnt[2] + 1LL * cnt[0] * (cnt[0] - 1) / 2 << endl;
  return 0;
}
