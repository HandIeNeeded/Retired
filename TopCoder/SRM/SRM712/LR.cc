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

class LR {
public:
  using LL = long long;

  void goLeft(std::vector<LL>& s) {
    std::vector<LL> r = s;
    for (int i = 0; i < s.size(); ++i) {
      if (i == 0) s[i] = r[0] + r.back();
      else s[i] = r[i] + r[i - 1];
    }
  }

  void goRight(std::vector<LL>& s) {
    std::vector<LL> r = s;
    for (int i = 0; i < s.size(); ++i) {
      if (i == s.size() - 1) s[i] = r[0] + r.back();
      else s[i] = r[i] + r[i + 1];
    }
  }

  bool isGood(std::vector<LL> &s, std::vector<LL> &r) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] > r[i]) return 0;
    }
    return 1;
  }

  string construct(vector<long long> s, vector<long long> t) {
    for (int L = 0; L <= 100; ++L) {
      if (!isGood(s, t)) break;
      std::vector<LL> r = s;
      for (int R = 0; R <= 100; ++R) {
        if (L + R <= 100) {
          if (!isGood(r, t)) break;
          if (r == t) {
            return string(L, 'L') + string(R, 'R');
          }
          goRight(r);
        }
      }
      goLeft(s);
    }
    return "No solution";
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {0,1,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0,1,2,1,0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "LL"; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {0,0,0,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0,1,0,0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "No solution"; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {12,24,56,95,12,78,0,100,54,88}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "No solution"; verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {1,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {11,11,10}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RRRRR"; verify_case(3, Arg2, construct(Arg0, Arg1)); }
	void test_case_4() { long Arr0[] = {1,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {562949953421312,562949953421312}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL"; verify_case(4, Arg2, construct(Arg0, Arg1)); }
	void test_case_5() { long Arr0[] = {0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0,0,0,1,0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "No solution"; verify_case(5, Arg2, construct(Arg0, Arg1)); }
	void test_case_6() { long Arr0[] = {123,456}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {123,456}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(6, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  LR solver;
  solver.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
