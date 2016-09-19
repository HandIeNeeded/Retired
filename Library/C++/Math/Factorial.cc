namespace FC {
  static constexpr int N = max_size;
  static constexpr int MO = 1e9 + 7;
  using array = int[N];
  array factorial, inverse, fInverse;

  void GetFactorial() {
    inverse[0] = 0; inverse[1] = factorial[0] = 1;
    fInverse[0] = fInverse[1] = 1;
    for (int i = 1; i <= N - 1; ++i) factorial[i] = 1LL * i * factorial[i - 1] % MO;
    for (int i = 2; i <= N - 1; ++i) inverse[i] = 1LL * (MO - MO / i) * inverse[MO % i] % MO;
    for (int i = 2; i <= N - 1; ++i) fInverse[i] = 1LL * fInverse[i - 1] * inverse[i] % MO;
  }

  int C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return 1LL* factorial[a] * fInverse[b] % MO * fInverse[a - b] % MO;
  }
}

