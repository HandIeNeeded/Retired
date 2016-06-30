/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 24 Jun 2016 12:59:02 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 105;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n) {
    int pos = max_element(a, a + n - i) - a;
    if (pos != n - 1 - i) {
      for (int j = pos; j < n - 1 - i; j++) {
        cout << j + 1 << ' ' << j + 2 << endl;
        swap(a[j], a[j + 1]);
      }
    }
  }


  return 0;
}


