/*************************************************************************
  >         File: E.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 06 Aug 2016 07:27:59 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
const int K = 62;
LL a[N];

int Gauss(int n) {
  int rank = 0;
  for (int i = 0; i < K; i++) {
    bool find = 0;
    for (int j = rank; j < n; j++) {
      if (a[j] & (1LL << i)) {
        find = 1;
        swap(a[rank], a[j]);
        break;
      }
    }
    if (find) {
      for (int j = 0; j < n; j++) if (j != rank) {
        if (a[j] & (1LL << i)) {
          a[j] ^= a[rank];
        }
      }
      rank++
    }
  }
  return rank;
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int rank = Gauss(n);
  cerr << rank << endl;
  cout << (1LL << rank) - n << endl;

  return 0;
}
