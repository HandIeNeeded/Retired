#include <bits/stdc++.h>
using namespace std;

const int M = 23;
const int N = 50 - M;
using LL = long long;
LL dp[2][1 << M];
int mp[1 << 16];

class BrightLampsRemake {
public:
  int gauss(std::vector<LL>& numbers) {
    int n = numbers.size();
    LL bit = 1LL << 49;
    int rank = 0;
    for (int i = 0; i < 50; ++i, bit >>= 1) {
      int find = 0, id = -1;
      for (int j = rank; j < n; ++j) {
        if (numbers[rank] & bit) {
          find = 1;
          id = j;
          break;
        }
      }
      if (find) {
        std::swap(numbers[rank], numbers[id]);
        for (int i = 0; i < n; ++i) if (i != rank) {
          if (numbers[i] & bit) {
            numbers[i] ^= numbers[rank];
          }
        }
        rank++;
      }
    }
    return rank;
  }

  LL get(const string& s) {
    LL ans = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
      ans <<= 1;
      ans |= s[i] - '0';
    }
    return ans; 
  }

  void init() {
    for (int i = 0; i < (1 << 16); ++i) mp[i] = __builtin_popcount(i);
  }

  int getBit(LL x) {
    int ans = 0;
    static int mask = (1 << 16) - 1;
    for (int i = 0; i < 4; ++i) {
      ans += mp[x & mask];
      x >>= 16;
    }
    return ans;
  }

  vector<long long> maxAndCount(string init, vector <string> buttons) {
    std::vector<LL> numbers;
    this->init();
    int n = buttons.size();
    int X = get(init);
    for (int i = 0; i < n; ++i) numbers.push_back(get(buttons[i]));
    int rank = gauss(numbers);
    LL ans = 0;
    int mx = getBit(X);
    if (rank <= N) {
      ans = 1LL << (n - rank);
      LL res = 0;
      for (int i = 0; i < (1LL << rank); ++i) {
        LL now = X;
        for (int j = 0; j < rank; ++j) {
          if (i & (1 << j)) {
            now ^= numbers[j];
          }
        }
        int tmp = getBit(now);
        if (tmp > mx) {
          mx = tmp;
          res = 1;
        } else if (tmp == mx) {
          res++;
        }
      }
      ans *= res;
    } else {
      std::cerr << "[Line #" << __LINE__ << "] fuck !!!" << std::endl;
      //dp[n][mask] here
      ans = 1LL << (n - rank);
      dp[0][0] = 1;
      int cur = 0;
      for (int i = 0; i < rank; ++i) {

      }
    }
    std::vector<LL> result{mx, ans};
    return result;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "0000"; string Arr1[] = {"1010", "0100", "0001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {4, 1 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, maxAndCount(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1011"; string Arr1[] = {"0000", "0000", "0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {3, 8 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, maxAndCount(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "00000"; string Arr1[] = {"11000", "01100", "00110", "00011", "10001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {4, 10 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, maxAndCount(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "10000"; string Arr1[] = {"11000", "01100", "00110", "00011", "10001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {5, 2 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, maxAndCount(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "0"; string Arr1[] = {"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
 "0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {0, 1125899906842624 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, maxAndCount(Arg0, Arg1)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  BrightLampsRemake ___test;
  ___test.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
