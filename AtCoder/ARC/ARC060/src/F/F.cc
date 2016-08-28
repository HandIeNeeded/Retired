/*************************************************************************
  >         File: F.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sun 28 Aug 2016 09:12:17 PM CST
*************************************************************************/
#include <bits/stdc++.h>

const int N = 4444;
const int MO = 1e9 + 7;
int dpCnt[N], cnt[N];

class KMP {
private:
  int fail[N];
  std::string s;

  void Build(const std::string& s) {
    this->s = s;
    fail[0] = fail[1] = 0;
    for (int i = 1; i < int(s.size()); i++) {
      int j = fail[i];
      while (j && s[j] != s[i]) j = fail[j];
      fail[i + 1] = s[j] == s[i] ? j + 1 : 0;
    }
  }

public:
  bool isGood(const std::string &s) {
    if (s.size() <= 1) return true;
    Build(s);
    int shift = s.size() - fail[s.size()];
    return fail[s.size()] == 0 || s.size() % shift != 0;
  }
}kmp;

void Add(int &x, int y) {
  x += y;
  if (x >= MO) x -= MO;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  dpCnt[0] = 1, cnt[0] = 0;
  for (int end = 1; end <= (int) s.size(); end++) {
    cnt[end] = s.size() + 1;
    for (int start = 1; start <= end; start++) {
      if (kmp.isGood(s.substr(start - 1, end - start + 1))) {
        if (cnt[end] > cnt[start - 1] + 1) {
          dpCnt[end] = dpCnt[start - 1];
          cnt[end] = cnt[start - 1] + 1;
        }
        else if (cnt[end] == cnt[start - 1] + 1) {
          Add(dpCnt[end], dpCnt[start - 1]);
        }
      }
    }
  }
  std::cout << cnt[s.size()] << std::endl;
  std::cout << dpCnt[s.size()] << std::endl;
  return 0;
}
