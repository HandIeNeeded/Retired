/*************************************************************************
  > File Name: B.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Mon 09 May 2016 12:25:05 AM CST
 *************************************************************************/

#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

const int N = 1e5 + 5;
LL sum[N];
int dp[N][2], a[N], b[N], prefix[N];
int cnt[N << 2];

#define L (x << 1)
#define R (x << 1 | 1)
#define MID ((l + r) >> 1)
#define LC L, l, MID
#define RC R, MID + 1, r

void build(int x, int l, int r) {
  if (l == r) cnt[x] = INT_MAX;
  else {
    build(LC), build(RC);
    cnt[x] = INT_MAX;
  }
}

int ql, qr, qx, qd;

void update(int x, int l, int r) {
  if (l == r) cnt[x] = qd;
  else {
    if (qx <= MID) update(LC);
    else update(RC);
    cnt[x] = min(cnt[L], cnt[R]);
  }
}

int query(int x, int l, int r) {
  if (ql <= l && qr >= r) return cnt[x];
  else {
    int a = INT_MAX, b = INT_MAX;
    if (ql <= MID) a = query(LC);
    if (qr > MID) b = query(RC);
    return min(a, b);
  }
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n, h;
    scanf("%d%d", &n, &h);
    REPP(i, 1, n) scanf("%d", a + i);
    REPP(i, 1, n) scanf("%d", b + i);
    REPP(i, 1, n) sum[i] = sum[i - 1] + a[i];
    REPP(i, 1, n) prefix[i] = prefix[i - 1] + b[i];
    build(1, 1, n);
    REPP(i, 1, n) {
      if (b[i] == 1) {
        dp[i][0] = INT_MAX;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
        continue;
      }
      else {
        LL pos = sum[i] - h;
        int index = upper_bound(sum + 1, sum + i + 1, pos) - sum;
        if (prefix[i] - prefix[index - 1]) {
          dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        else {
          ql = index, qr = i;
          dp[i][0] = query(1, 1, n);
        }
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        qx = i, qd = dp[i][1];
        update(1, 1, n);
      }
    }
    //REPP(i, 1, n) {
    //  cout << dp[i][0] << ' ' << dp[i][1] << endl;
    //}
    printf("%d\n", min(dp[n][0], dp[n][1]));
  }
  return 0;
}

