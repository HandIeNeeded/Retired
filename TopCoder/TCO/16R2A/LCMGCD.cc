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

class LCMGCD {
public:

#define YES return "Possible"
#define NO return "Impossible"

  std::pair<int, int> getPair(int x) {
    int a = 0, b = 0;
    while (x > 1 && x % 2 == 0) x >>= 1, a++;
    while (x > 1 && x % 3 == 0) x /= 3, b++;
    return {a, b};
  }

  string isPossible(vector <int> x, int t) {
    int count = std::count(x.begin(), x.end(), t);
    if (int(x.size()) == count) YES;
    if (count >= 2) YES;
    int X, Y;
    std::tie(X, Y) = getPair(t);
    std::cerr << "# X << ' '  << Y # is " << X << ' '  << Y << std::endl;
    int cnt[3][3] = {0};
    for (auto &y: x) if (y != t) {
      int a, b;
      std::tie(a, b) = getPair(y);
      std::cerr << "# a << ' '  << b # is " << a << ' '  << b << std::endl;
      int ta, tb;
      if (a < X) ta = 0; 
      if (a == X) ta = 1;
      if (a > X) ta = 2;
      if (b < Y) tb = 0; 
      if (b == Y) tb = 1;
      if (b > Y) tb = 2;
      cnt[ta][tb]++;
    }
    int sameRow = 0, sameColumn = 0;
    for (int i = 0; i < 3; ++i) sameRow += cnt[1][i];
    for (int i = 0; i < 3; ++i) sameColumn += cnt[i][1];
    if (sameRow && count) YES;
    if (sameColumn && count) YES;
    if (count && (!sameRow && !sameColumn)) {
      if (cnt[0][0] || cnt[2][2]) YES;
      if (cnt[0][2] && cnt[2][0]) YES;
    }
    if (cnt[0][1] && cnt[1][2]) {
      if (cnt[2][0]) YES;
    }
    if (cnt[2][1] && cnt[1][2]) YES;
    if (cnt[2][1] && cnt[1][0]) {
      if (cnt[0][2]) YES;
    }
    if (cnt[0][1] && cnt[1][0]) YES;
    NO;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Possible"; verify_case(0, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(1, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,12,24,18,36,72,54,108,216}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; string Arg2 = "Possible"; verify_case(2, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6,27,81,729}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(3, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; string Arg2 = "Possible"; verify_case(5, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {100663296, 544195584, 229582512, 59049}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60466176; string Arg2 = "Possible"; verify_case(6, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {2,4,8,16,32,64}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 256; string Arg2 = "Impossible"; verify_case(7, Arg2, isPossible(Arg0, Arg1)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  LCMGCD solver;
  solver.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
