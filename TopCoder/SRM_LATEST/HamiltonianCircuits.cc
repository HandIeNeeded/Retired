#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <bitset>
#include <utility>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

class HamiltonianCircuits {
public:
  vector <int> findCircuit(int n, int seed, int a, int b, int c, vector <int> d, vector <int> e);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arr5[] = {0,0,1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {1,2,2}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = { }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(0, Arg7, findCircuit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arr5[] = {0,1,1,2,3,3}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {3,0,2,0,1,2}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {1, 2, 0, 3 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(1, Arg7, findCircuit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arr5[] = {0,0,1,2,2,3,1,0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {1,3,2,0,3,1,0,1}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {1, 2, 0, 3 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(2, Arg7, findCircuit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arr5[] = {5, 4, 4, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {3, 5, 2, 4, 5, 3, 0, 5, 4, 3, 2, 5, 4, 3, 1}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {3, 4, 2, 0, 1, 5 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(3, Arg7, findCircuit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 987654323; int Arg2 = 999777888; int Arg3 = 979797979; int Arg4 = 987654323; int Arr5[] = {0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {1}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = { }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(4, Arg7, findCircuit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 8; int Arg1 = 2018; int Arg2 = 1337; int Arg3 = 10001; int Arg4 = 10007; int Arr5[] = {0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {2}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {3, 4, 0, 1, 2, 7, 6, 5 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(5, Arg7, findCircuit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 315301770; int Arg2 = 177340464; int Arg3 = 2067825; int Arg4 = 144591777; int Arr5[] = {45,29,34,41,36,27,28,3,20,48,44,33,20,42,0,47,1,7,5,20}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {6,8,9,2,23,7,6,22,42,19,5,21,34,8,28,22,6,21,44,29}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); int Arr7[] = {47, 45, 49, 43, 42, 40, 39, 37, 36, 35, 33, 34, 32, 31, 29, 26, 30, 28, 25, 24, 20, 21, 16, 14, 18, 13, 11, 9, 8, 12, 10, 7, 5, 4, 3, 2, 1, 0, 6, 15, 17, 19, 22, 23, 27, 38, 41, 44, 46, 48 }; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(6, Arg7, findCircuit(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

vector <int> HamiltonianCircuits::findCircuit(int n, int seed, int a, int b, int c, vector <int> d, vector <int> e) {

}
//Created by Yuan Lei

// BEGIN CUT HERE
HamiltonianCircuits solver;

int main() {
  solver.run_test(-1);
  
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
