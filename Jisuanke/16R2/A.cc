/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 03 Jul 2016 01:19:25 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (auto i = (a); i <= (b); i++)
using namespace std;

const int N = 305;
int mp[N][N], dis[N], vis[N], n;
int tmp[2][N];

void GetShortestPath(int a, int b) {
  REPP(i, 1, n) tmp[0][i] = mp[i][b], tmp[1][i] = mp[b][i];
  REPP(i, 1, n) dis[i] = -1, vis[i] = 0;
  REPP(i, 1, n) mp[i][b] = mp[b][i] = -1;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  dis[a] = 0;
  q.push({0, a});
  while (q.size()) {
    int x, d;
    tie(d, x) = q.top(); q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    REPP(i, 1, n) if (mp[x][i] >= 0 && (dis[i] == -1 || dis[i] > dis[x] + mp[x][i])) {
      dis[i] = dis[x] + mp[x][i];
      q.push({dis[i], i});
    }
  }
  REPP(i, 1, n) mp[i][b] = tmp[0][i], mp[b][i] = tmp[1][i];
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  scanf("%d", &n);
  REPP(i, 1, n) {
    REPP(j, 1, n) scanf("%d", &mp[i][j]);
  }
  //n = 300;
  //REPP(i, 1, n) REPP(j, 1, n) mp[i][j] = max(-1, rand() % 10000 - 2000);
  clock_t st = clock();
  LL ans = 0;
  REPP(i, 1, n) {
    REPP(j, 1, n) if (i != j) {
      GetShortestPath(i, j);
      for (int k = 1; k <= n; k++) if (k != j) {
        //cout << i << ' ' << j << ' ' << k << ' ' << dis[k] << endl;
        ans += dis[k];
      }
    }
  }
  cout << ans << endl;
  cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
  return 0;
}


