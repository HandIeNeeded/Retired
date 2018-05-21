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

class BuildingSpanningTreesDiv1 {
public:
  int getNumberOfSpanningTrees(int n, vector <int> x, vector <int> y);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, getNumberOfSpanningTrees(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(1, Arg3, getNumberOfSpanningTrees(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(2, Arg3, getNumberOfSpanningTrees(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, getNumberOfSpanningTrees(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arr1[] = {1,4,2,3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,7,6,5,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 144; verify_case(4, Arg3, getNumberOfSpanningTrees(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 1000; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 529013784; verify_case(5, Arg3, getNumberOfSpanningTrees(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

const int N = 1111;
const int MO = 987654323;
int f[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
using LL = long long;

int Powd(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1) {
    if (y & 1) ans = 1LL * ans * x % MO;
    x = 1LL * x * x % MO;
  }
  return ans;
}

int BuildingSpanningTreesDiv1::getNumberOfSpanningTrees(int n, vector <int> x, vector <int> y) {
  std::iota(f + 1, f + n + 1, 1);
  int m = x.size();
  int cnt = n;
  for (int i = 0; i < m; ++i) {
    int tx = find(x[i]);
    int ty = find(y[i]);
    if (tx == ty) return 0;
    f[tx] = ty;
    cnt--;
  }
  if (cnt == 1) return 1;
  map<int, int> has;
  for (int i = 1; i <= n; ++i) {
    has[find(i)]++;
  }
  LL ans = 1;
  for (auto &p: has) ans = 1LL * ans * p.second % MO;
  return 1LL * ans * Powd(n, cnt - 2) % MO;
}
//Created by Yuan Lei

// BEGIN CUT HERE
BuildingSpanningTreesDiv1 solver;

int main() {
  solver.run_test(-1);
  
  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
