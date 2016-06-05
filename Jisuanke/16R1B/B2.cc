/*************************************************************************
	> File Name: B2.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 05 Jun 2016 01:35:42 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 4005;
const int MO = (1 << 30) - 1;

int f[N][N], g[N][N];
int d[N][N];
int vis[N], p[N], tot, mobius[N] = {0, 1};
int sum[N];
 
void prime() {
	for (int i = 2; i < N; i++) {
		if (!vis[i]) p[tot++] = i, mobius[i] = -1;
		for (int j = 0; j < tot && i * p[j] < N; j++) {
			vis[i * p[j]] = p[j];
			mobius[i * p[j]] = -mobius[i];
			if (i % p[j] == 0) {
				mobius[i * p[j]] = 0;
				break;
			}
		}
	}
	REPP(i, 1, N - 1) sum[i] = sum[i - 1] + mobius[i];
}

int get(int a, int b) {
  if (g[a][b] >= 0) return g[a][b];
  int &ans = g[a][b];
  ans = 0;
  //cout << a << ' ' << b << endl;
  for (int i = 1; i <= a; i += 1) {
    //int x = a / i, y = b / i;
    //int pa = a / x, pb = b / y;
    int x = d[a][i], y = d[b][i];
    int pa = d[a][x], pb = d[b][y];
    int nextpos = min(pa, pb);
    ans += x * y * (sum[nextpos] - sum[(i - 1)]);
    //cout << i << ' ' << nextpos << endl;
    i = nextpos;
  } 
  return ans;
}

void Init() {
  REPP(i, 1, 2000) {
    REPP(j, i, 2000) {
      d[i][j] = i / j;
      f[i][j] = f[j][i] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + get(i, j) - get(i / 2, j / 2);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t;
  clock_t st = clock();
  memset(g, -1, sizeof(g));
  prime();
  Init();
  REPP(i, 1, 4) {
    REPP(j, 1, 4) {
      cerr << f[i][j] << ' ';
    }
    cerr << endl;
  }
  cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    //cout << f[n - 1][m - 1] << endl;
    int ans = f[n - 1][m - 1] << 1;
    ans += n + m;
    cout << (ans & MO) << endl;
  }
  return 0;
}


