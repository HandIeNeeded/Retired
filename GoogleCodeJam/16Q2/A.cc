/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 28 May 2016 10:01:59 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

string str = "PRS";
int a[10], b[10], tot;
int n, r, p, s;

int win(int x, int y) {
  if (x > y) swap(x, y);
  if (x == 0 && y == 1) return 0;
  if (x == 1 && y == 2) return 1;
  if (x == 0 && y == 2) return 2;
  return -1;
}

bool check() {
  int cnt = tot;
  REP(i, tot) b[i] = a[i];
  while (cnt > 1) {
    int now = 0;
    for (int i = 0; i < cnt; i += 2) {
      b[now++] = win(b[i], b[i + 1]);
      if (b[now - 1] < 0) return 0;
    }
    cnt >>= 1;
  }
  return 1;
}

string result;

string dfs(int x, int dep) {
  if (dep == n) {
    return string(1, str[x]);
  }
  else {
    if (x == 0) {
      string a = dfs(0, dep + 1), b = dfs(1, dep + 1);
      if (a > b) swap(a, b);
      return a + b;
    }
    else if (x == 1) {
      string a = dfs(1, dep + 1), b = dfs(2, dep + 1);
      if (a > b) swap(a, b);
      return a + b;
    }
    else {
      string a = dfs(0, dep + 1), b = dfs(2, dep + 1);
      if (a > b) swap(a, b);
      return a + b;
    }
  }
}

bool good(int x) {
  result = dfs(x, 0);
  int cnt[3] = {0};
  REP(i, tot) {
    int pos = str.find(result[i]);
    cnt[pos]++;
  }
  return cnt[0] == p && cnt[1] == r && cnt[2] == s;
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
    cin >> n >> r >> p >> s;
    tot = 1 << n;
    string answer = "Z";
    REP(i, 3) if (good(i)) {
      answer = min(answer, result);
    }
    cout << "Case #" << ca++ << ": ";
    if (answer == "Z") {
      cout << "IMPOSSIBLE" << endl;
    }
    else {
      cout << answer << endl;
    }
  }
  return 0;
}



