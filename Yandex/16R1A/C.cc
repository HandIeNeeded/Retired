/*************************************************************************
	> File Name: C.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 09:20:26 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int scores[31] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int a[10];

const int N = 50;
int match[N], vis[N], n;
vector<int> edge[N];
//vis[x] 右边x有没有被访问过 match[x] 右边x所匹配的边

bool dfs(int x) {//x为来自左边的点
  for (auto &y: edge[x]) if (!vis[y]) {
    vis[y] = 1;
    if (match[y] == -1 || dfs(match[y])) {
      match[y] = x;
      return true;
    }
  }
  return false;
}

int Hungarian(){
  int ans = 0;
  memset(match, -1, sizeof(match));
  REP(i, n) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) ans++;
  }
  return ans;
}


int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  REP(i, 10) cin >> a[i];
  n = 10;
  int ans = 0;
  REP(pos, 31) {
    int score = scores[pos];
    REP(i, 10) edge[i].clear();
    REP(i, 10) {
      REP(j, 31) if (j != pos) {
        if (a[i] + scores[j] >= score) {
          edge[i].push_back(j);
        }
      }
    }
    //cout << score << ' ' << Hungarian() << endl;
    if (Hungarian() < 10) {
      ans = pos + 1;
    }
    else {
      break;
    }
  }
  int result = -1;
  if (ans == 0) {
    result = 0;
  }
  else if (ans == 31) {
    result = 1000;
  }
  else result = ans;
  cout << result << endl;

  return 0;
}


