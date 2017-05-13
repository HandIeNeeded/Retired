#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <utility>
#include <sstream>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class WaterAndOxygen {
public:

  int sign(long double x) {
    if (fabsl(x) < 1e-12L) return 0;
    else if (x > 0) return 1;
    return -1;
  }

  double maxDays(int remainH20, int remainO2, int costH2O, int costO2) {
    long double lo = 0, hi = remainH20 + remainO2 + 100;
    for (int i = 0; i < 100; ++i) {
      long double mid = (lo + hi) / 2.0L;
      if (sign(mid * costH2O - remainH20) > 0) hi = mid;
      else {
        long double extra = (remainH20 - mid * costH2O) / 2.0L;
        if (sign(extra + remainO2 - mid * costO2) < 0) hi = mid;
        else lo = mid;
      }
    }
    return lo;
  }

  double maxDays2(int remainH20, int remainO2, int costH2O, int costO2) {
    double rh = remainH20, ro = remainO2, ch = costH2O, co = costO2;
    double r = min(rh / ch, ro / co);
    rh -= r * ch;
    ro -= r * co;
    double l = 0, h = (int) rh;
    double mx = 0;
    while (1) {

      double m = (h + l) / 2;
      double o2 = m / 2. + ro;
      double h2 = rh - m;
      if ((o2 / costO2) - (h2 / costH2O) > 0) {
        h = m;
      } else {
        l = m;
      }
      mx = max(mx, min(h2 / costH2O, o2 / costO2));
      if (abs(l - h) < .0000001) {
        break;
      }
    }
    return r + mx;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 64; int Arg1 = 70; int Arg2 = 3; int Arg3 = 7; double Arg4 = 12.0; verify_case(0, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 99; int Arg1 = 102; int Arg2 = 1; int Arg3 = 1; double Arg4 = 99.0; verify_case(1, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 101; int Arg1 = 99; int Arg2 = 1; int Arg3 = 1; double Arg4 = 99.66666666666667; verify_case(2, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 123456789; int Arg1 = 987654321; int Arg2 = 123; int Arg3 = 456; double Arg4 = 1003713.731707317; verify_case(3, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 987654321; int Arg1 = 123456789; int Arg2 = 456; int Arg3 = 123; double Arg4 = 1758643.7307692308; verify_case(4, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 13; int Arg3 = 27; double Arg4 = 0.0; verify_case(5, Arg4, maxDays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  WaterAndOxygen solver;
  srand(time(0) % clock());

  while (1) {
    int a = rand() % (int) (1e9) + 1;
    int b = rand() % (int) (1e9) + 1;
    int c = rand() % (int) (10) + 1;
    int d = rand() % (int) (10) + 1;
    long double A = solver.maxDays(a, b, c, d);
    long double B = solver.maxDays2(a, b, c, d);
    if (solver.sign(A - B) && solver.sign((A - B) / A)) {
      std::cout << A << ' ' << B << std::endl;
      std::cout << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
    }
  }

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
