#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <utility>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cassert>
#include <numeric>
#include <iomanip>
using namespace std;

class RainbowSocks {
public:
  double getPairProb(vector <int> socks, int colorDiff);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 1.0; verify_case(0, Arg2, getPairProb(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 50, 50, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 0.3333333333333333; verify_case(1, Arg2, getPairProb(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {44, 14, 24, 31, 30, 32, 46, 23, 27, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; double Arg2 = 0.8222222222222222; verify_case(2, Arg2, getPairProb(Arg0, Arg1)); }

// END CUT HERE

};

double RainbowSocks::getPairProb(vector <int> socks, int colorDiff) {
  int n = socks.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) if (i < j) {
      if (std::abs(socks[i] - socks[j]) <= colorDiff) ans++;
    }
  }
  return 2.0 * ans / (n * (n - 1));

}// Created by Yuan Lei

// BEGIN CUT HERE
RainbowSocks solver;

int main() {
  solver.run_test(-1);
  
  cerr << "-----------------------------------" << endl;
  cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}

// END CUT HERE



