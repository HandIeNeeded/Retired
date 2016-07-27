/*************************************************************************
  > File Name: dictionary-pagination.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Wed 27 Jul 2016 12:30:51 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

vector<string> str;

int main() {
  ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  str.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  sort(str.begin(), str.end());
  while (q--) {
    string tmp;
    int x;
    cin >> tmp >> x;
    int pos = lower_bound(str.begin(), str.end(), tmp) - str.begin();
    cout << pos / x + 1 << endl;
  }


  return 0;
}
