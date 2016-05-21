/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 21 May 2016 10:54:32 AM CST
*************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 11;
double p[N][N];
int idx[N];

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int n;
  cin >> n;
  REP(i, n) idx[i] = i;
  REP(i, n) REP(j, n) cin >> p[i][j];
  double answer = 0;
  do {
    double result = 1.0;
    REP(i, n) {
      REPP(j, i + 1, n - 1) {
        result *= p[idx[i]][idx[j]];
      }
    }
    answer += result;
  }while (next_permutation(idx, idx + n));
  cout << fixed << setprecision(10) << answer << endl;
  return 0;
}


