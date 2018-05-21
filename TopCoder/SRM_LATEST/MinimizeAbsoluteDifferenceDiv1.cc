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

class MinimizeAbsoluteDifferenceDiv1 {
public:
  vector <int> findTuple(vector <int> x);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findTuple(Arg0)); }
	void test_case_1() { int Arr0[] = {2,3,5,7,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 1, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findTuple(Arg0)); }
	void test_case_2() { int Arr0[] = {8, 2, 4, 2, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findTuple(Arg0)); }
	void test_case_3() { int Arr0[] = {124, 182, 9, 33, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findTuple(Arg0)); }
	void test_case_4() { int Arr0[] = {9947, 3, 7, 11, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 3, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findTuple(Arg0)); }
	void test_case_5() { int Arr0[] = {10000, 4, 10, 4, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, findTuple(Arg0)); }

// END CUT HERE

};

using LL = long long;
typedef pair<LL, LL> PII;

bool cmp(PII a, PII b) {
  return a.first * b.second - a.second * b.first > 0;
}

vector <int> MinimizeAbsoluteDifferenceDiv1::findTuple(vector <int> x) {
  vector<int> tmp(5, 0);
  for (int i = 0; i < 5; ++i) tmp[i] = i;
  PII ans = {1e9, 1};
  vector<int> best;
  do {
    PII now = {abs(x[tmp[0]] * 1LL * x[tmp[3]] - x[tmp[1]] * 1LL * x[tmp[2]]), 1LL * x[tmp[1]] * x[tmp[3]]};
    if (cmp(ans, now)) {
      ans = now;
      best = tmp;
    }
  } while (std::next_permutation(tmp.begin(), tmp.end()));
  best.pop_back();
  return best;
}
//Created by Yuan Lei

// BEGIN CUT HERE
MinimizeAbsoluteDifferenceDiv1 solver;

int main() {
  solver.run_test(-1);
  
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
