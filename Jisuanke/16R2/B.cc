/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 03 Jul 2016 01:55:03 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (auto i = (a); i <= (b); i++)
using namespace std;

void update(int &x, int y) {
  if (y >= x) x = y;
}

int Get(int a, int b, int c) {
  if (a + b + c == 0) return 0;
  vector<int> num;
  num.push_back(a), num.push_back(b), num.push_back(c);
  sort(num.begin(), num.end());
  a = num[0], b = num[1], c = num[2];
  if (b + a >= c - 1) return a + b + c;
  else return 2 * (b + a) + 1;
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    //type 1 (A, B, C) most
    int x = min(a, min(b, c)), y = max(a, max(b, c));
    int lo = 0, hi = x + 1;
    //cout << lo << ' ' << ans << endl;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      int ta = a - mid, tb = b - mid, tc = c - mid;
      if (ta < 0 || tb < 0 || tc < 0) {
        hi = mid;
        continue;
      }
      if (ta > tb) swap(ta, tb);
      int cnt;
      if (tb >= 2 * ta) {
        cnt = ta;
      }
      else cnt = (ta + tb) / 3;
      if (cnt >= mid - 1) lo = mid;
      else hi = mid;
    }
    {
      int ta = a - lo, tb = b - lo, tc = c - lo;
      if (ta > tb) swap(ta, tb);
      int cnt;
      if (tb >= 2 * ta) {
        cnt = ta;
      }
      else cnt = (ta + tb) / 3;
      ans = max(ans, cnt + lo);
    }
    //cout << lo << ' ' << ans << endl;
    //type 2 (A, B, B) most
    lo = 0, hi = y + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      int ta = a - mid, tb = b - 2 * mid, tc = c;
      if (ta < 0 || tb < 0 || tc < 0) {
        hi = mid;
        continue;
      }
      int cnt = min(tb, min((tc + ta) / 2, ta));
      if (cnt >= mid - 1) lo = mid;
      else hi = mid;
    }
    {
      int ta = a - lo, tb = b - 2 * lo, tc = c;
      int cnt = min(tb, min((tc + ta) / 2, ta));
      ans = max(ans, lo + cnt);
    }
    //cout << lo << ' ' << ans << endl;

    //type 3 (A, A, B) most
    lo = 0, hi = y + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      int ta = a - 2 * mid, tb = b - mid, tc = c;
      if (ta < 0 || tb < 0 || tc < 0) {
        hi = mid;
        continue;
      }
      int cnt = min(ta, min((tc + tb) / 2, tb));
      if (cnt >= mid - 1) lo = mid;
      else hi = mid;
    }
    {
      int ta = a - 2 * lo, tb = b - lo, tc = c;
      tb += tc;
      int cnt = min(ta, min((tc + tb) / 2, tb));
      ans = max(ans, lo + cnt);
    }
    //cout << lo << ' ' << ans << endl;
    cout << ans << endl;
  }

  return 0;
}


