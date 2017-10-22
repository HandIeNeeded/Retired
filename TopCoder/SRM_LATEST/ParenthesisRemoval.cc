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

class ParenthesisRemoval {
public:
  int countWays(string s);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "()()()()()"; int Arg1 = 1; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arg0 = "(((())))"; int Arg1 = 24; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arg0 = "((()()()))"; int Arg1 = 54; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arg0 = "(())(())(())"; int Arg1 = 8; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arg0 = "((((())((((((((((()((((((()))))())))))()))))))))))"; int Arg1 = 948334170; verify_case(4, Arg1, countWays(Arg0)); }

// END CUT HERE

};

int ParenthesisRemoval::countWays(string s) {

}// Created by Yuan Lei

// BEGIN CUT HERE
ParenthesisRemoval solver;

int main() {
  solver.run_test(-1);
  
  cerr << "-----------------------------------" << endl;
  cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}

// END CUT HERE



