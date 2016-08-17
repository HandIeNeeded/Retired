#include <bits/stdc++.h>

template<class T>
void merge_sort(T first, T last) {
  if (last - first > 1) {
    auto middle = first + (last - first) / 2;
    merge_sort(first, middle);
    merge_sort(middle, last);
    std::inplace_merge(first, middle, last);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::vector<int> a, b, c;
  int n = 5, m = 7;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);
  for (int i = 0; i < n; i++) a.emplace_back(dis(gen));
  for (int i = 0; i < m; i++) b.emplace_back(dis(gen));
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << std::setprecision(6) << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  
  return 0;
}
