/*************************************************************************
	> File Name: CHSGMNTS.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 10 Jul 2016 03:46:14 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1005;
int a[N];
vector<int> positions[N];

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> numbers;
    REPP(i, 1, n) cin >> a[i], numbers.push_back(a[i]);
    sort(numbers.begin(), numbers.end());
    numbers.resize(unique(numbers.begin(), numbers.end()) - numbers.begin());
    REPP(i, 1, n) a[i] = lower_bound(numbers.begin(), numbers.end(), a[i]) - numbers.begin();
    REPP(i, 1, n) positions[a[i]].push_back(i);

  }

  return 0;
}


