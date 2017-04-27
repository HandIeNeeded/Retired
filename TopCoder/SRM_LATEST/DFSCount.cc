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
using namespace std;

class DFSCount {
public:
  long long count(vector <string> G);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYY",
 "YNYY",
 "YYNN",
 "YYNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYYYYYYYYYYYY",
 "YNYYYYYYYYYYYY",
 "YYNYYYYYYYYYYY",
 "YYYNYYYYYYYYYY",
 "YYYYNYYYYYYYYY",
 "YYYYYNYYYYYYYY",
 "YYYYYYNYYYYYYY",
 "YYYYYYYNYYYYYY",
 "YYYYYYYYNYYYYY",
 "YYYYYYYYYNYYYY",
 "YYYYYYYYYYNYYY",
 "YYYYYYYYYYYNYY",
 "YYYYYYYYYYYYNY",
 "YYYYYYYYYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 87178291200LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

long long DFSCount::count(vector <string> G) {

}
//Created by Yuan Lei

// BEGIN CUT HERE
DFSCount solver;

int main() {
  solver.run_test(-1);
  
  cerr << "-----------------------------------" << endl;
  cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}

// END CUT HERE



