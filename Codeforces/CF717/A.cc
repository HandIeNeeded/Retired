/*************************************************************************
  >         File: A.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Mon 12 Sep 2016 08:26:15 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using LL = long long;

template<int BASE = 5>
class NS {
  static const LL MO = 1e9 + 7;
  LL a, b; //Number System of BASE: a + b * sqrt(BASE);

public:
  static inline void Normalize(LL& x) { x %= MO; if (x < 0) x += MO; }
  inline LL first() const { return a; }
  inline LL second() const { return b; }

  NS (LL a = 0, LL b = 0) : a(a), b(b) {
    Normalize(this->a); Normalize(this->b);
  }

  static LL Powd(LL a, LL b) {
    assert(b >= 0);
    LL answer = 1;
    for (; b > 0; b >>= 1) {
      if (b & 1) answer = answer * a % MO;
      a *= a; a %= MO;
    }
    return answer;
  }

  friend std::ostream& operator << (std::ostream& os, const NS& number) {
    os << " { " << number.a << " + " << number.b << " * [" << BASE << " } ";
    return os;
  }

  NS Pair() const { return NS(a, -b); }

  NS Inverse() const {
    if (!a && !b) {
      std::cerr << "0 has no INVERSE!!!" << std::endl;
      return NS();
    } else if (b == 0) {
      return NS(Powd(a, MO - 2), 0);
    } else {
      LL down = a * a % MO + MO - BASE * b % MO * b % MO;
      return (*this).Pair() * Powd(down % MO, MO - 2);
    }
  }

  NS operator - () const { return NS(-a, -b); }
  NS operator + (const NS& rhs) const { return NS(a + rhs.a, b + rhs.b); }
  NS operator - (const NS& rhs) const { return NS(a - rhs.a, b - rhs.b); }
  NS operator * (const NS& rhs) const { return NS(a * rhs.a % MO + b * rhs.b % MO * BASE % MO, a * rhs.b % MO + b * rhs.a % MO); }
  NS operator * (LL scale) const { return *this * NS(scale, 0); }
  NS operator / (const NS& rhs) const { return *this * rhs.Inverse(); }
};
using NS5 = NS<5>;
constexpr int N = 222;
NS5 Comb[N][N], S[N][N];

void Init() {
  Comb[0][0] = S[0][0] = 1;
  for (int i = 1; i < N; i++) {
    Comb[i][0] = Comb[i][i] = 1;
    S[i][0] = 0, S[i][i] = S[i - 1][i - 1] * NS5(i).Inverse();
    for (int j = 1; j < i; j++) {
      Comb[i][j] = Comb[i - 1][j] + Comb[i - 1][j - 1];
      NS5 A = NS5(i).Inverse(), B = A - 1;
      S[i][j] = S[i - 1][j] * B + S[i - 1][j - 1] * A;
    }
  }
}

NS5 Powd(NS5 a, LL b) {
  assert(b >= 0);
  NS5 answer{1};
  for (; b > 0; b >>= 1) {
    if (b & 1) answer = answer * a;
    a = a * a;
  }
  return answer;
}

NS5 Calc(LL x, NS5 start, NS5 magic) {
  NS5 result = NS5(1) - Powd(magic, x);
  result = start * result;
  result = result * (NS5(1) - magic).Inverse();
  return result;
}

NS5 SumK(LL x, int b) {
  // \sum_{i=1}^x Fib[i]^b
  NS5 answer;
  NS5 magic = NS5(0, 1).Inverse();
  NS5 P = NS5(1, 1) / 2, Q = P.Pair();
  for (int i = 0; i <= b; i++) {
    NS5 result = Powd(NS5(-1), i) * Comb[b][i];
    NS5 start = Powd(P, (b - i)) * Powd(Q, i);
    //start == 1
    if (start.first() == 1 && start.second() == 0) {
      answer = answer + result * start * x;
      continue;
    }
    answer = answer + result * Calc(x, start, start);
  }
  return answer * Powd(magic, b);
}

LL Solve(LL x, int k) {
  NS5 answer;
  for (int i = 0; i <= k; i++) {
    answer = answer + S[k][i] * SumK(x, i);
  }
  return answer.first();
}

int main() {
  int k; LL l, r;
  Init();
  std::cin >> k >> l >> r;
  LL answer = Solve(r + 2, k) - Solve(l + 1, k);
  NS5::Normalize(answer);
  std::cout << answer << std::endl;
  return 0;
}
