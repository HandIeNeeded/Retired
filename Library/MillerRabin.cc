LL mul(LL a, LL b, LL MO) {
  a %= MO;
  LL ans = 0;//not 1
  while (b) {
    if (b & 1) add(ans, a, MO);
    b >>= 1;
    add(a, a, MO);
  }
  return ans;
}

LL pmod(LL a, LL b, LL MO) {
  LL ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a, MO);
    b >>= 1;
    a = mul(a, a, MO);
  }
  return ans;
}

bool test(LL n, LL b) {
  LL m = n - 1, cnt = 0;
  while (~m & 1) {
    m >>= 1;
    cnt++;
  }
  LL ans = pmod(b, m, n);
  if (ans == 1 || ans == n - 1) return 1;
  cnt--;
  while (cnt >= 0) {
    ans = mul(ans, ans, n);
    if (ans == n - 1) return 1;
    cnt--;
  }
  return 0;
}

const int BASE[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool check(LL n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n == 3215031751LL) return 0;
  for (int i = 0; i < 12 && BASE[i] < n; ++i) {
    if (!test(n, BASE[i])) return 0;
  }
  return 1;
}
