/*************************************************************************
	> File Name: F.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 21 May 2016 10:45:14 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
vector<int> edge[N];
int out[N];

int main() {
  int t, ca = 1;
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    REPP(i, 1, n) edge[i].clear();
    REP(i, m) {
      int x, y;
      cin >> x >> y;
      edge[x].push_back(y);
      out[y]++;
    }
    priority_queue<int> candidates;
    REPP(i, 1, n) if (out[i] == 0) candidates.push(i);
    vector<int> answer;
    while (candidates.size()) {
      int x = candidates.top(); candidates.pop();
      answer.push_back(x);
      for (const auto&y: edge[x]) {
        out[y]--;
        if (out[y] == 0) candidates.push(y);
      }
    }
    //for (const auto&x: answer) {
    //  cout << x << ' ';
    //}
    //cout << endl;
    LL result = 0;
    int now = n + 1;
    for (int i = 0; i < n; i++) {
      now = min(now, answer[i]);
      result += now;
    }
    cout << result << endl;
  }
  return 0;
}



