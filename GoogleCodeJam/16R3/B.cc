/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 10:38:57 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 105;

char mp[N];
int a[N];
string str[N];
vector<int> orders[N * N * N];
string res[N * N * N];
int now, tot;

vector<int> edge[N];
vector<int> que[N];
int in[N][N], n;

void GetStrs(int dep = 0) {
  if (now == tot) return ;
  if (dep == n) {
    if (now < tot) {
      now++;
    }
    return ;
  }
  if (dep == 0) {
    REP(i, n) if (in[dep][i] == 0) {
      que[dep].push_back(i);
    }
  }
  random_shuffle(que[dep].begin(), que[dep].end());
  int x = que[dep].back();
  que[dep].pop_back();
  orders[now].push_back(x);
  que[dep + 1] = que[dep];
  for (auto &y: edge[x]) {
    in[dep][y]--;
    if (in[dep][y] == 0) {
      que[dep + 1].push_back(y);
    }
  }
  GetStrs(dep + 1);
}

int GetCount(const string& str) {
  int cnt = 0;
  REP(i, tot) {
    if (res[i].find(str) != string::npos) {
      cnt++;
    }
  }
  return cnt;
}


int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) {
      if (a[i]) {
        in[0][i]++;
        edge[a[i]].push_back(i);
      }
    }
    REPP(i, 1, n - 1) {
      REP(j, n) in[i][j] = in[0][j];
    }
    cin >> mp;
    int m;
    cin >> m;
    REP(i, m) {
      cin >> str[i];
    }
    tot = 10000;
    GetStrs();
    cout << "Case #" << ca++ << ":";
    REP(i, tot) {
      REP(j, n) res[i] += mp[orders[i][j]];
    }
    REP(i, m) {
      cout << " " << GetCount(str[i]) / tot;
    }
    cout << endl;
  }
  return 0;
}


