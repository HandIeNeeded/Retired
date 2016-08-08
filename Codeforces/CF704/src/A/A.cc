/*************************************************************************
  >         File: A.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 07 Aug 2016 10:10:22 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int N = 3e5 + 5;
deque<int> idx[N];
int in[N];

int main() {
  ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  int ans = 0;
  int now = 1, mx = 0;
  while (q--) {
    int type, x;
    cin >> type >> x;
    if (type == 1) {
      in[now] = x;
      ans++;
      idx[x].push_back(now++);
    }
    else if (type == 2) {
      for (auto &y: idx[x]) {
        ans--;
        in[idx[x].front()] = -1;
        idx[x].pop_front();
      }
    }
    else {
      if (x > mx) {
        for (int i = mx + 1; i <= x; i++) {
          if (in[i] < 0) continue;
          if (idx[in[i]].size()) {
            ans--;
            idx[in[i]].pop_front();
          }
        }
        mx = x;
      }
    }
    cout << ans << endl;
  }


  return 0;
}
