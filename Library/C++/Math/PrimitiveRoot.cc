namespace PR {
  int euler, G, prime;
  std::vector<int> factors;
  
  int Powd(int x, int y, int MO) {
    int answer = 1;
    for (; y > 0; y >>= 1) {
      if (y & 1) answer = 1LL * answer * x % MO;
      x = 1LL * x * x % MO;
    }
    return answer;
  }

  void GetFactor(int euler) {
    factors.clear();
    for (int i = 2; i * i <= euler; ++i) {
      if (euler % i == 0) {
        factors.emplace_back(i);
        while (euler % i == 0) euler /= i;
      }
    }
    if (euler > 1) factors.emplace_back(euler);
  }

  //prime ^ k, 2 * prime ^ k, 2, 4
  int GetRoot(int p) {
    if (p == 2) return 1;
    if (p == 4) return 3;
    prime = p, euler = p - 1; 
    GetFactor(euler);
    for (int i = 1; i <= euler; ++i) {
      bool bad = false;
      for (auto &factor: factors) {
        if (Powd(i, euler / factor, prime) == 1) {
          bad = 1;
          break;
        }
      }
      if (!bad) return G = i;
    }
    return 0;
  }
}

