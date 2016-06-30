/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 24 Jun 2016 01:47:02 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int a[10];

int GetNum(LL x) {
  if (x == 0) return 1;
  int ans = 0;
  while (x) {
    ans++;
    x /= 7;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  REP(i, 10) a[i] = i;
  int n, m;
  cin >> n >> m;
  int ans = 0;
  int T = 10;
  do {
    if (a[0] == 0) continue;
    for (int i = 0; i < T; i++) {
      for (int j = 1; j <= i; j++) {
        //for (int k = 0; k < j; k++) {
        //  cout << a[k] << ' ';
        //}
        //cout << ": ";
        //for (int k = j; k <= i; k++) {
        //  cout << a[k] << ' ';
        //}
        //cout << endl;

        if (j != i && a[j] == 0) continue;
        LL left = 0, right = 0;
        for (int k = 0; k < j; k++) left = 10 * left + a[k];
        if (left >= n) continue;
        for (int k = j; k <= i; k++) right = 10 * right + a[k];
        if (right >= m) continue;
        LL tot = left * m + right;
        int count = i + 1;
        if (a[0] == 0) count--;
        int base7 = GetNum(tot);
        if (base7 < count) {
          bool bad = 0;
          for (int k = 0; k <= i; k++) if (a[k] == 0) {
            bad = true;
            break;
          }
          if (!bad) {
            cout << "Got 1: " << tot << endl;
            ans++;
          }
        }
        else {
          cout << "Got 1: " << tot << endl;
          ans++;
        }
      }
    }
  }while (next_permutation(a, a + T));
  cout << ans << endl;
  return 0;
}


