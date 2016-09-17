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


