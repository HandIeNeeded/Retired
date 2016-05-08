/*************************************************************************
  > File Name: B.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sun 01 May 2016 12:43:27 AM CST
 *************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int n;
LL diff;
string coder, jammer;

bool match(char a, char b) {
  if (a == '?' || b == '?') return 1;
  else return a == b;
}

void dfs(string a, string b, int dep) {
  //cout << a << ' ' << b << endl;
  if (dep == n) {
    LL A = stoll(a), B = stoll(b);
    if (diff > abs(A - B)) {
      diff = abs(A - B);
      coder = a, jammer = b;
    }
    else if (diff == abs(A - B)) {
      if (A < stoll(coder)) {
        coder = a, jammer = b;
      }
      else if (A == stoll(coder)) {
        if (B < stoll(jammer)) {
          coder = a, jammer = b;
        }
      }
    }
  }
  else {
    REPP(i, '0', '9') {
      REPP(j, '0', '9') {
        if (match(i, a[dep]) && match(j, b[dep])) {
          char pa = a[dep], pb = b[dep];
          a[dep] = i, b[dep] = j;
          dfs(a, b, dep + 1);
          a[dep] = pa, b[dep] = pb;
        }
      }
    }
  }
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif

  ios::sync_with_stdio(0);
  int t, ca = 1;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    n = a.size();
    diff = LLONG_MAX;
    dfs(a, b, 0);
    cout << "Case #" << ca++ << ": " << coder << ' ' << jammer << endl;
  }


  return 0;
}


