namespace PM {
  static constexpr int N = max_size;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array mark, prime, mobius;
  int count = 0;
  std::vector<int> factor[N];

  void GetPrime() {
    factor[1].emplace_back(1);
    for (int i = 2; i < N; ++i) {
      if (!mark[i]) {
        prime[count++] = i;
        mobius[i] = MO - 1;
        factor[i].emplace_back(i);
      }
      for (int j = 0; j < count && i * prime[j] < N; ++j) {
        int now = i * prime[j];
        mark[now] = prime[j];
        mobius[now] = (MO - mobius[i]) % MO;
        factor[now] = factor[i];
        factor[now].emplace_back(prime[j]);
        if (i % prime[j] == 0) {
          mobius[now] = 0;
          factor[now].pop_back();
          break;
        }
      }
    }
  }
}
