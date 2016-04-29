/*************************************************************************
  > File Name: B.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 30 Apr 2016 01:10:16 AM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
int a[N];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  REPP(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  int sum = 0;
  REPP(i, 1, n - 1) sum += a[i];
  cout << a[n] - sum + 1 << endl;
  return 0;
}


