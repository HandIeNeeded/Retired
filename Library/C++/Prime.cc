void add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int tot, vis[N], p[N], fac[N], inv[N], finv[N], mobius[N];
vector<int> factor[N];

void prime() {
  factor[1].push_back(1);
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      p[tot++] = i;
      mobius[i] = MO - 1;
      factor[i].push_back(i);
    }
    for (int j = 0; j < tot && i * p[j] < N; j++) {
      int now = i * p[j];
      vis[now] = p[j];
      mobius[now] = (MO - mobius[i]) % MO;
      factor[now] = factor[i];
      factor[now].push_back(p[j]);
      if (i % p[j] == 0) {
        mobius[now] = 0;
        factor[now].pop_back();
        break;
      }
    }
  }

  inv[0] = 0, inv[1] = 1, fac[0] = 1;
  finv[0] = finv[1] = 1;
  REPP(i, 1, N - 1) fac[i] = 1LL * i * fac[i - 1] % MO;
  REPP(i, 2, N - 1) inv[i] = 1LL * (MO - MO / i) * inv[MO % i] % MO;
  REPP(i, 2, N - 1) finv[i] = 1LL * finv[i] * inv[i] % MO;
}

int C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return 1LL * fac[a] * finv[b] % MO * finv[a - b] % MO;
}
