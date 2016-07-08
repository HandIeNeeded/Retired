/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 08 Jul 2016 03:19:14 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 2e5 + 5;
int a[N], dp[N], vis[N];
vector<int> edge[N];

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  REPP(i, 1, n) {
    edge[i].push_back(i + 1);
    edge[i + 1].push_back(i);
    int x;
    cin >> x;
    edge[i].push_back(x);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  REPP(i, 1, n) dp[i] = INT_MAX;
  dp[1] = 0;
  q.push({0, 1});
  while (q.size()) {
    int x = q.top().second; q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto &y: edge[x]) {
      if (y > n) continue;
      if (dp[y] > dp[x] + 1) {
        dp[y] = dp[x] + 1;
        q.push({dp[y], y});
      }
    }
  }
  REPP(i, 1, n) {
    cout << dp[i] << ' ';
  }
  cout << endl;


  return 0;
}


