/*************************************************************************
  > File Name: C.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sun 01 May 2016 01:36:38 AM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e3 + 5;
map<string, int> mp;
map<string, int> tmp;
vector<int> str[N];
bool vis[N];

int main() {
  int t, ca = 1;
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int tot = 0, num = 0;
    mp.clear(), tmp.clear();
    memset(vis, 0, sizeof(vis));
    REPP(i, 1, n) {
      string a, b;
      cin >> a >> b;
      int A, B;
      if (!mp.count(a)) mp[a] = tot++;
      A = mp[a];
      if (!tmp.count(b)) tmp[b] = num++;
      B = tmp[b];
      str[A].push_back(B);
    }
    int ans = 0;
    REP(i, tot) {
      vector<int> left, right;
      REP(j, str[i].size()) {
        if (vis[str[i][j]]) {
          left.push_back(str[i][j]);
        }
        else {
          right.push_back(str[i][j]);
        }
      }
      int now = 0;
      REP(j, right.size()) {
        vis[str[i][j]] = 1;
        now++;
      }
      REP(j, left.size()) {
        if(now) ans++;
        now++;
      }
    }
    cout << "Case #" << ca++ << ": " << ans << endl;
    REP(i, tot) str[i].clear();
  }
  return 0;
}
