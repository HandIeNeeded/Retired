#include <bits/stdc++.h>
using namespace std;

class AlphabetOrderDiv1 {
public:

  static const int N = 33;
  int mp[N][N], in[N];
  std::vector<int> edges[N];

  string isOrdered(vector <string> words) {
    for (int i = 0; i < 26; ++i) edges[i].clear();
    memset(mp, 0, sizeof(mp));
    memset(in, 0, sizeof(in));
    for (auto &s: words) {
      int n = s.size();
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (i < j) {
            int a = s[i] - 'a';
            int b = s[j] - 'a';
            if (a != b && mp[b][a] == 1) {
              return "Impossible";
            }
            mp[a][b] = 1;
          }
        }
      }
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (mp[i][j] && i != j) {
          in[j]++;
          edges[i].push_back(j);
        }
      }
    }
    std::queue<int> q;
    for (int i = 0; i < 26; ++i) if (in[i] == 0) {
      q.push(i);
    }
    std::cerr << "# q.size() # is " << q.size() << std::endl;
    int cnt = 0;
    while (q.size()) {
      int x = q.front(); q.pop();
      cnt++;
      for (auto &y: edges[x]) {
        in[y]--;
        if (in[y] == 0) q.push(y);
      }
    }
    std::cerr << "# cnt # is " << cnt << std::endl;
    if (cnt < 26) return "Impossible";
    return "Possible";
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"single","round","match"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, isOrdered(Arg0)); }
	void test_case_1() { string Arr0[] = {"topcoder","topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, isOrdered(Arg0)); }
	void test_case_2() { string Arr0[] = {"algorithm", "contest"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(2, Arg1, isOrdered(Arg0)); }
	void test_case_3() { string Arr0[] = {"pink","floyd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(3, Arg1, isOrdered(Arg0)); }
	void test_case_4() { string Arr0[] = {"gimnasia","y","esgrima","la","plata"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(4, Arg1, isOrdered(Arg0)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  AlphabetOrderDiv1 ___test;
  ___test.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
