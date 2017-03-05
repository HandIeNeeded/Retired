#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int K = 1 << N;

int dp[2][64][K];

class Xscoregame {
public:

  void toMax(int &x, int y) {
    if (x < y) x = y;
  }

  int getscore(vector <int> A) {
    int n = A.size();
    int T = 1 << n;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      for (int left = 0; left < 64; ++left) {
        for (int use = 0; use < T; ++use) {
          if (dp[cur][left][use] >= 0) {
            int t = dp[cur][left][use] - left;
            for (int j = 0; j < n; ++j) {
              if (use & (1 << j)) continue;
              int newLeft = (left + (left ^ A[j])) & 63;
              toMax(dp[cur ^ 1][newLeft][use | (1 << j)], t * 2 + left + (left ^ A[j]));
            }
          }
        }
      }
      memset(dp[cur], -1, sizeof(dp[cur]));
      cur ^= 1;
    }
    int ans = -1;
    for (int i = 0; i < 64; ++i) {
      toMax(ans, dp[cur][i][T - 1]);
    }
    return ans;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, getscore(Arg0)); }
	void test_case_1() { int Arr0[] = {10,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 80; verify_case(1, Arg1, getscore(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getscore(Arg0)); }
	void test_case_3() { int Arr0[] = {1,0,1,0,1,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 170; verify_case(3, Arg1, getscore(Arg0)); }
	void test_case_4() { int Arr0[] = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 830122; verify_case(4, Arg1, getscore(Arg0)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  Xscoregame ___test;
  ___test.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
