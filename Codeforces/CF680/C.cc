/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 09 Jun 2016 12:43:19 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 50;
int p[N], vis[N], tot;

int prime() {
  for (int i = 2; i < N; i++) {
    if (!vis[i]) p[tot++] = i;
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}

int main() {
  prime();
  int cnt = 0;
  vector<int> numbers;
  REP(i, tot) {
    numbers.push_back(p[i]);
    if (p[i] < 10) numbers.push_back(p[i] * p[i]);
  }
  for (auto &x: numbers) {
    cout << x << endl;
    cout << flush;
    string str;
    cin >> str;
    if (str == "yes") cnt++;
  }
  if (cnt >= 2) {
    cout << "composite" << endl;
  }
  else {
    cout << "prime" << endl;
  }


  return 0;
}


