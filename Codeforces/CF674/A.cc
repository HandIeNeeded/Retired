/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 07 May 2016 11:37:17 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 5005;
int ans[N], cnt[N], a[N];

int main() {
  int t, ca = 1;
  int n;
  cin >> n;
  REPP(i, 1, n) cin >> a[i];
  REPP(i, 1, n) {
    REPP(j, 1, n) cnt[j] = 0;
    int mx = 0;
    REPP(j, i, n) {
      cnt[a[j]]++;
      if (cnt[a[j]] > cnt[mx]) {
        ans[a[j]]++;
        mx = a[j];
      }
      else if (cnt[a[j]] == cnt[mx] && a[j] < mx) {
        ans[a[j]]++;
        mx = a[j];
      }
      else {
        ans[mx]++;
      }
    }
  }
  REPP(i, 1, n) cout << ans[i] << ' ';
  cout << endl;


  return 0;
}



