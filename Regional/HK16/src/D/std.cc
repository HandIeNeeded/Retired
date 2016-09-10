#include <bits/stdc++.h>

const int N = 1e5 + 5;
int A[N], B[N];

int main() {
  std::ios::sync_with_stdio(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) std::cin >> A[i];
  for (int i = 0; i < n; ++i) std::cin >> B[i];
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    int cnt[2][200] = {0};
    for (int i = l; i <= r; i++) {
      cnt[0][A[i]]++;
      cnt[1][B[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < 200; ++i) {
      ans += std::min(cnt[0][i], cnt[1][i]);
    }
    std::cout << ans << std::endl;
  }
  
  return 0;
}
