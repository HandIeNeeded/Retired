#include <bits/stdc++.h>
using namespace std;

class AncientGameRecord {
public:

  int minimalRemove(int n, int m, vector <int> x, vector <int> y, string d) {

  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0,1,1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "DRUL"; int Arg5 = 0; verify_case(0, Arg5, minimalRemove(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "LU"; int Arg5 = 1; verify_case(1, Arg5, minimalRemove(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0,0,0,1,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,1,1,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "RLDDRL"; int Arg5 = 1; verify_case(2, Arg5, minimalRemove(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0,0,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "ULDR"; int Arg5 = 4; verify_case(3, Arg5, minimalRemove(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 6; int Arr2[] = {0,5,4,1,3,2,5,4,2,2,5,4,1,3,2,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,4,1,1,1,2,3,5,4,2,0,2,0,0,2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "DRULLLUDRUDLRUDL"; int Arg5 = 4; verify_case(4, Arg5, minimalRemove(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};//Created by Riho.Yoshioka

// BEGIN CUT HERE
int main() {
  AncientGameRecord ___test;
  ___test.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
