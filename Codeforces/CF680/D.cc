/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Thu 09 Jun 2016 01:35:57 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

LL sqr(int x) {
  return 1LL * x * x * x;
}

int get(LL x) {
  int a = 0;
  while (sqr(a + 1) <= x) a++;
  return a;
}

int main() {
  //LL A = 100;
  //int best = 0;
  //for (LL i = 1; i <= A; i++) {
  //  LL x = i;
  //  cout << x << " = ";
  //  int cnt = 0;
  //  while (x) {
  //    int y = get(x);
  //    x -= sqr(y);
  //    cout << y << " + ";
  //    cnt++;
  //  }
  //  cout << "cnt: " << cnt;
  //  best = max(best, cnt);
  //  cout << endl;
  //}
  //cout << "Best: " << best << endl;
  LL m;
  cin >> m;
  int now = 1;
  vector<int> numbers;
  LL sum = 0;
  while (1) {
    int next = now + 1;
    LL a = sqr(now), b = sqr(next);
    while (a + sum <= m && a + sum < b) {
      numbers.push_back(now);
      sum += a;
    }
    if (a + sum > m) break;
    now++;
  }
  LL prefix = 0;
  REP(i, numbers.size()) prefix += sqr(numbers[i]);
  for (auto it = numbers.rbegin(); it != numbers.rend(); it++) {
    int x = *it;
    prefix -= sqr(x);
    while (prefix + sqr(x + 1) <= m) x++;
    *it = x;
    m -= sqr(x);
  }
  sum = 0;
  REP(i, numbers.size()) sum += sqr(numbers[i]);
  cout << numbers.size() << ' ' << sum << endl;

  return 0;
}


