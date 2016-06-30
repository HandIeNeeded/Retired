/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 30 Jun 2016 01:09:06 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 106;
char mp[N];
bool good[N];

int main() {
  ios::sync_with_stdio(0);
  int n, d;
  cin >> n >> d;
  REP(i, d) {
    cin >> mp;
    int pos = find(mp, mp + n, '0') - mp;
    if (pos == n) {
      good[i] = 0;
    }
    else {
      good[i] = 1;
    }
  }
  int ans = 0;
  REP(i, d) {
    if (!good[i]) continue;
    int j = i; 
    while (j < d && good[j]) j++;
    ans = max(ans, j - i);
    i = j - 1;
  }
  cout << ans << endl;

  return 0;
}


