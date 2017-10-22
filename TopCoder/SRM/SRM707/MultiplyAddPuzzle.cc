#include <bits/stdc++.h>
using namespace std;

class MultiplyAddPuzzle {
public:

  long long minimalSteps(long long s, long long t, long long a, long long b) {

  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 40LL; long long Arg2 = 4LL; long long Arg3 = 2LL; long long Arg4 = 2LL; verify_case(0, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = 28LL; long long Arg2 = 4LL; long long Arg3 = 2LL; long long Arg4 = 2LL; verify_case(1, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 10LL; long long Arg1 = 99LL; long long Arg2 = 4LL; long long Arg3 = 2LL; long long Arg4 = -1LL; verify_case(2, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 345LL; long long Arg1 = 12345LL; long long Arg2 = 1LL; long long Arg3 = 10LL; long long Arg4 = 895LL; verify_case(3, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 1000000000000000000LL; long long Arg2 = 1000000000000000000LL; long long Arg3 = 1000000000000000000LL; long long Arg4 = 0LL; verify_case(4, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};//Created by Riho.Yoshioka

// BEGIN CUT HERE
int main() {
  MultiplyAddPuzzle ___test;
  ___test.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
