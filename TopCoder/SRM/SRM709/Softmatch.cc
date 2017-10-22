#include <bits/stdc++.h>
using namespace std;

const int N = 300;
const int Z = 4;

#define REP(i, n) for (int i = 0; i < (int) (n); ++i)

struct Automation{
  int tr[N][Z], fail[N], val[N], node;

  int Node() {
    memset(tr[node], 0, sizeof(tr[node]));
    fail[node] = 0;
    return node++;
  }

  void Init() {
    node = 0;
    Node();
  }

  void Insert(char *s, int y) {
    int pos = 0, x, now = 0;
    while (s[pos]) {
      x = s[pos++] - '0';
      if (!tr[now][x]) {
        tr[now][x] = Node();
      }
      now = tr[now][x];
    }
    val[now] = y;
  }

  void Build() {
    int x, y;
    queue<int> q;
    REP(i, Z) {
      x = tr[0][i];
      if (x) {
        fail[x] = 0;
        q.push(x);
      }
    }

    while (!q.empty()) {
      x = q.front(); q.pop();
      REP(i, Z) {
        if (!tr[x][i]) {
          tr[x][i] = tr[fail[x]][i];
          continue;
        }
        y = tr[x][i];
        q.push(y);
        fail[y] = tr[fail[x]][i];
        val[y] += val[fail[y]];
      }
    }
  }
}AC;

int dp[55][N];

class Softmatch {
public:

  int get(char c) {
    if (c == 'a') return 0 + 1 * 8;
    if (c == 'A') return 2 + 3 * 8;
    if (c == 'b') return 0 + 2 * 8;
    if (c == 'B') return 1 + 3 * 8;
    return -1;
  }

  void toMax(int &x, int y) {
    if (x < y) x = y;
  }

  int count(string S, vector <string> patterns) {
    AC.Init();
    static char tmp[55];
    for (auto &s: patterns) {
      std::copy(s.begin(), s.end(), tmp);
      AC.Insert(tmp, 1);
    }
    AC.Build();
    std::cerr << "# AC.node # is " << AC.node << std::endl;
    for (int i = 0; i < 5; ++i) {
      std::cerr << "# AC.val[i] # is " << AC.val[i] << std::endl;
    }
    int n = S.size();
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int node = 0; node < N; ++node) {
        if (dp[i][node] < 0) continue;
        {
          int x = get(S[i]);
          int a = x & 7, b = x >> 3;
          int next = AC.tr[node][a];
          int cost = AC.val[next];
          std::cerr << "# next << ' ' << cost # is " << next << ' ' << cost << std::endl;
          toMax(dp[i + 1][next], dp[i][node] + cost);
          next = AC.tr[node][b];
          cost = AC.val[next];
          std::cerr << "# next << ' ' << cost # is " << next << ' ' << cost << std::endl;
          toMax(dp[i + 1][next], dp[i][node] + cost);
        }
        {
          int x = get(S[i] + 'A' - 'a');
          int a = x & 7, b = x >> 3;
          int next = AC.tr[node][a];
          int cost = AC.val[next];
          std::cerr << "# next << ' ' << cost # is " << next << ' ' << cost << std::endl;
          toMax(dp[i + 1][next], dp[i][node] + cost);
          next = AC.tr[node][b];
          cost = AC.val[next];
          std::cerr << "# next << ' ' << cost # is " << next << ' ' << cost << std::endl;
          toMax(dp[i + 1][next], dp[i][node] + cost);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < N; ++i) {
      toMax(ans, dp[n][i]);
    }
    return ans;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaa"; string Arr1[] = {"03","21"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aba"; string Arr1[] = {"03","11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "bba"; string Arr1[] = {"00","00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "bbbbbb"; string Arr1[] = {"1110","011","100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abbaa"; string Arr1[] = {"123"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aababbaab"; string Arr1[] = {"012","332","101", "0313"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  Softmatch ___test;
  ___test.run_test(0);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
