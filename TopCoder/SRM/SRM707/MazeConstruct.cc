#include <bits/stdc++.h>
using namespace std;

class MazeConstruct {
public:

  vector <string> construct(int k) {
    std::vector<std::string> res;
    k++;
    if (k <= 50) {
      string ans = string(k, '.');
      res.push_back(ans);
      return res;
    } else {
      for (int row = 50; row >= 1; --row) {
        int mod = row + 1;
        int cnt = k / mod;
        int ret = k % mod;
        if (cnt % 2 == 0) {
          ret = row - ret;
          if (ret & 1) {
            ret++;
            string ans = string(row, '#');
            ans[0] = '.';
            res.push_back(ans);
          }
          for (int i = 0; i < cnt; ++i) {
            res.push_back(string(row, '.'));
            string ans = string(row, '#');
            if (i & 1) ans[0] = '.';
            else ans[row - 1] = '.';
            if (i == cnt - 1) {
              ret >>= 1;
              for (int j = 0; j < ret; ++j) {
                ans[j + 1] = '.';
              }
            }
            res.push_back(ans);
          }
          res.push_back(string(row, '.'));
          for (int i = 0; i < res.size(); ++i) {
            std::cout << res[i] << std::endl;
          }
          return res;
        } 
      }
    }
    return res;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 4; string Arr1[] = {"...", "...", "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"..#..", "#.#..", "..#..", ".#...", "....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }

// END CUT HERE

};//Created by Riho.Yoshioka

// BEGIN CUT HERE
int main() {
  MazeConstruct ___test;
  ___test.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  ___test.construct(99);
  return 0;
}
// END CUT HERE
