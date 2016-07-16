/*************************************************************************
	> File Name: D.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Fri 15 Jul 2016 02:17:43 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 201;
const int Z = 26;
const LL INF = 1LL << 60;

int a[N], K;
char str[N];

struct Automation{
  int tr[N][Z], fail[N], val[N], node;

  int Node() {
    memset(tr[node], 0, sizeof(tr[node]));
    fail[node] = 0;
    return node++;
  }

  void Init() {
    node = 0;
    Node();
  }

  void Insert(char *s, int y) {
    int pos = 0, x, now = 0;
    while (s[pos]) {
      x = s[pos++] - 'a';
      if (!tr[now][x]) {
        tr[now][x] = Node();
      }
      now = tr[now][x];
    }
    val[now] += y;
  }

  void Build() {
    int x, y;
    queue<int> q;
    REP(i, Z) {
      x = tr[0][i];
      if (x) {
        fail[x] = 0;
        q.push(x);
      }
    }

    while (!q.empty()) {
      x = q.front(); q.pop();
      REP(i, Z) {
        if (!tr[x][i]) {
          tr[x][i] = tr[fail[x]][i];
          continue;
        }
        y = tr[x][i];
        q.push(y);
        fail[y] = tr[fail[x]][i];
        val[y] += val[fail[y]];
      }
    }
  }
}AC;

typedef LL Matrix[N][N];
Matrix ret, tmp, base;

void mul(Matrix &a,Matrix &b) {
  for(int i = 0; i < K; i++) for (int j = 0; j < K; j++) tmp[i][j] = (i == j) ? 0 : -INF;
  for(int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
    for (int k = 0; k < K; k++) tmp[i][j] = max(tmp[i][j], a[i][k] + b[k][j]);
  }
  for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) a[i][j] = tmp[i][j];
}

void powd(LL b) {
  for(int i = 0; i < K; i++) for (int j = 0; j < K; j++) ret[i][j] = (i == j) ? 0 : -INF;
  for(; b; b >>= 1) {
    if (b & 1) mul(ret, base);
    mul(base, base);
  }
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  LL k;
  cin >> n >> k;
  AC.Init();
  REPP(i, 1, n) cin >> a[i];
  REPP(i, 1, n) {
    cin >> str;
    AC.Insert(str, a[i]);
  }
  AC.Build();
  K = AC.node;
  for (int i = 0; i < K; i++) {
   for (int j = 0; j < K; j++) {
     base[i][j] = -INF;
   }
  }
  REP(i, AC.node) {
    REP(j, Z) {
      base[i][AC.tr[i][j]] = max(base[i][AC.tr[i][j]], 1LL * AC.val[AC.tr[i][j]]);
    }
  }
  powd(k);
  LL ans = 0;
  REP(i, K) ans = max(ans, ret[0][i]);
  cout << ans << endl;

  return 0;
}
