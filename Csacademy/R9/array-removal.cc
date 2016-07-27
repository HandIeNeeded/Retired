/*************************************************************************
  > File Name: array-removal.cc
  > Author: Riho.Yoshioka
  > Mail:   riho.yoshioka@yandex.com
  > Created Time: Wed 27 Jul 2016 12:02:15 AM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 1e5 + 5;
int a[N];
LL prefix[N];

typedef pair<LL, pair<int, int>> unit;

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  ios::sync_with_stdio(0);
  int n;
  multiset<unit> s;
  set<pair<int, int>> sp;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    prefix[i] = prefix[i - 1] + a[i];
  }
  s.insert({prefix[n], {1, n}});
  sp.insert({n, 1});
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    auto p = *s.rbegin();
    cout << p.first << endl;
    int L, R;
    auto key = sp.lower_bound({x, 0});
    tie(R, L) = *key;
    auto pos = s.find({prefix[R] - prefix[L - 1], {L, R}});
    s.erase(pos);
    sp.erase({R, L});
    if (x - 1 >= L) {
      s.insert({prefix[x - 1] - prefix[L - 1], {L, x - 1}});
      sp.insert({x - 1, L});
    }
    if (x + 1 <= R) {
      s.insert({prefix[R] - prefix[x], {x + 1, R}});
      sp.insert({R, x + 1});
    }
    //for(auto p: s) {
    //  cout << p.second.first << ' ' << p.second.second << endl;
    //}
  }

  return 0;
}
