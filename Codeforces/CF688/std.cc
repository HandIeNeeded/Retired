#include <bits/stdc++.h>
using namespace std;

unsigned long long per = 1, n, k;

int main() {
  ios::sync_with_stdio(0);
  //cin >> n >> k;
  for (int x = 2; x < 500000; x++) {
    for (int y = 70; y < 1000; y++) {
      long long ll = 1;
      for (int i = 0; i < y; i++) {
        ll = ll * x;
      }
      if (ll > x && ll <= 1000000) {
        cout << ll << ' ' << x << ' ' << y << endl;
        return 0;
      }
    }
  }


  return 0;
}
