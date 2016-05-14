/*************************************************************************
  > File Name: C.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 14 May 2016 01:23:26 PM CST
 *************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const LL BASE = 1e9;

struct BigInteger {
  vector<LL> v; //v中倒序存放数字
  BigInteger () {}
  BigInteger (LL x) { init(x); }

  void init(LL x) {
    v.clear();
    if (x == 0) {
      v.push_back(0);
      return ;
    }
    while (x) {
      v.push_back(x % BASE);
      x /= BASE;
    }
  }

  BigInteger operator + (const BigInteger &b) const {
    LL m = max(v.size(), b.v.size()) + 1;
    BigInteger c;
    c.v.resize(m);//全0，注意不能c(m)这样写，因为这样是把c初始化成m
    LL st = 0, tmp, aa, bb;

    REP(i, m) {
      if (i >= (int) v.size()) aa = 0;
      else aa = v[i];
      if (i >= (int) b.v.size()) bb = 0;
      else bb = b.v[i];
      tmp = aa + bb + st;
      if (tmp >= BASE) st = 1, tmp -= BASE;
      else st = 0;
      c.v[i] = tmp;
    }
    while (c.v.size() > 1 && c.v.back() == 0) c.v.pop_back();
    return c;
  }

  BigInteger operator * (const BigInteger &b) const {
    BigInteger c; 
    c.v.resize(v.size() + b.v.size()); //max digit a+b 全0
    LL st = 0, tmp;
    REP(i, v.size()) {
      REP(j, b.v.size()) {
        tmp = v[i] * b.v[j] + c.v[i + j] + st; //tmp < base^2
        c.v[i + j] = tmp % BASE;
        st = tmp / BASE; //st < base
      }
      c.v[i + b.v.size()] = st, st = 0;
    }
    while (c.v.size() > 1 && c.v.back() == 0) c.v.pop_back(); 
    return c;
  }

  BigInteger operator / (const LL &n) const { //n != 0
    if (n == 0) {
      cout << "Error!" << endl;
      return 0;
    }

    BigInteger b;
    b.v.resize(v.size());
    LL st = 0, tmp;
    for (int i = v.size() - 1, j = 0; i >= 0; --i, j++) {
      tmp = st * BASE + v[i];
      b.v[j] = tmp / n;
      st = tmp % n;
    }
    reverse(b.v.begin(), b.v.end());
    while (b.v.size() > 1 && b.v.back() == 0) b.v.pop_back();
    return b;
  }

  LL operator % (const LL &n) const { //n != 0
    if (n == 0) {
      cout << "Error!" << endl;
      return 0;
    }

    LL st = 0, tmp;
    for (int i = v.size() - 1, j = 0; i >= 0; --i, j++) {
      tmp = st * BASE + v[i];
      st = tmp % n;
    }
    return st;
  }
};

void output(const BigInteger &num) {
  cout << num.v.back(); //最前面没有前导0，后面都是有前导零的
  int n = num.v.size() - 1;
  while (n) {
    cout << setw(9) << setfill('0') << num.v[--n]; //这里改变了cout对于固定宽度的输出的设置
  }
  cout << endl;
}

BigInteger answer[201];

void Init() {
  answer[1] = BigInteger(1), answer[2] = BigInteger(2);
  for (int i = 3; i <= 200; i++) answer[i] = answer[i - 1] + answer[i - 2];
}

int main() {
  int t, ca = 1;
  Init();
  while (cin >> t) {
    output(answer[t]);
  }
  return 0;
}

