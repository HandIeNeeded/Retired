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

class PlusSign {
public:
  int draw(vector <string> pixels);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#..",
 "#.#.",
 ".#..",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, draw(Arg0)); }
	void test_case_1() { string Arr0[] = {"..#....",
 ".......",
 "......#",
 ".......",
 ".......",
 ".......",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; verify_case(1, Arg1, draw(Arg0)); }
	void test_case_2() { string Arr0[] = {"#..",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, draw(Arg0)); }

// END CUT HERE

};

constexpr int N = 55;
int dp[N][N];

int count(int a, int b, int c, int d) {
  ++a, ++b, ++c, ++d;
  return dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1];
}

int PlusSign::draw(vector <string> pixels) {
  int n = pixels.size();
  int m = pixels[0].size();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + (pixels[i - 1][j - 1] == '#') - dp[i - 1][j - 1];
    }
  }
  int total = dp[n][m];
  std::cerr << "# total # is " << total << std::endl;
  int ans = N * N;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      for (int R = 1; R < n; ++R) {
        if (x - R < 0 || x + R >= n || y - R < 0 || y + R >= m) continue;
        for (int r = 1; r <= R; ++r) {
          if (count(x - R, y - R, x + R, y + R) != total) continue;
          if (count(x - R, y - R, x - R + r - 1, y - R + r - 1)) continue;
          if (count(x - R, y + R - r + 1, x - R + r - 1, y + R)) continue;
          if (count(x + R - r + 1, y - R, x + R, y - R + r - 1)) continue;
          if (count(x + R - r + 1, y + R - r + 1, x + R, y + R)) continue;
          ans = std::min(ans, (2 * R + 1) * (2 * R + 1) - 4 * r * r - total);
        }
      }
    }
  }
  if (ans == N * N) ans = -1;
  return ans;
}// Created by Yuan Lei

// BEGIN CUT HERE
PlusSign solver;

int main() {
  solver.run_test(-1);
  
  cerr << "-----------------------------------" << endl;
  cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  return 0;
}

// END CUT HERE



