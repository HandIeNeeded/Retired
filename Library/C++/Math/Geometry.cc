namespace GM {
  using LL = long long; // replace it with double when necessary
  using Point = std::complex<LL>;
  
  inline LL Dot(const Point &a, const Point &b) { return std::real(std::conj(a) * b) };
  inline LL Det(const Point &a, const Point &b) { return std::imag(std::conj(a) * b) };


}
