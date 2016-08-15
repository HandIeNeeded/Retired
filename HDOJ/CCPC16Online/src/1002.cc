/*************************************************************************
  >         File: 1002.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 14 Aug 2016 02:43:39 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 2000;

int visited[N], p[N], tot;

void Prime() {
  for (int i = 2; i < N; i++) {
    if (!visited[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      visited[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  int t, ca = 1;
  Prime();
  cout << tot << endl;


  return 0;
}
