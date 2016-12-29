#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <utility>
#include <queue>
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

class TreeDistanceConstruction {
public:
  static const int N = 55;
  std::vector<int> edges[N];
  int n;

  vector<int> bfs(int st) {
    std::vector<int> answer(n);
    answer[st] = 0;
    queue<int> q;
    q.push(st);
    while (q.size()) {
      int x = q.front(); q.pop();
      for(auto &y: edges[x]) {
        if (y == st || answer[y]) continue;
        answer[y] = answer[x] + 1;
        q.push(y);
      }
    }
    return answer;
  }

  vector<int> get() {
    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
      vector<int> dis = bfs(i);
      answer[i] = *std::max_element(dis.begin(), dis.end());
    }
    return answer;
  }

  vector <int> construct(vector <int> d) {
    int A = *std::min_element(d.begin(), d.end());
    int B = *std::max_element(d.begin(), d.end());
    std::vector<int> answer;
    std::vector<int> L, R;
    n = int(d.size());
    for (int i = 0; i < n; ++i) edges[i].clear();
    for (int i = A; i <= B; ++i) {
      if (std::find(d.begin(), d.end(), i) == d.end()) return answer;
      for (int x = 0; x < n; ++x) {
        if (d[x] == i) R.emplace_back(x);
      }
      L.emplace_back(R.back());
      R.pop_back();
    }
    int cnt = L.size();
    for (int i = 0; i < cnt - 1; ++i) {
      answer.push_back(L[i]);
      answer.push_back(L[i + 1]);
      edges[L[i]].push_back(L[i + 1]);
      edges[L[i + 1]].push_back(L[i]);
    }
    std::reverse(R.begin(), R.end());
    for (int i = 0; i < int(R.size()); ++i) {
      int j = i;
      while (j < int(R.size()) && d[R[j]] == d[R[i]]) j++;
      if (j == int(R.size())) break;
      for (int k = i; k < j; ++k) {
        answer.push_back(R[j]);
        answer.push_back(R[k]);
        edges[R[j]].push_back(R[k]);
        edges[R[k]].push_back(R[j]);
      }
      i = j - 1;
    }
    for(auto &y: R) {
      if (d[y] == d[R.back()]) {
        answer.push_back(y);
        answer.push_back(L[0]);
        edges[y].push_back(L[0]);
        edges[L[0]].push_back(y);
      }
    }
    if (get() != d) return std::vector<int> ();
    return answer;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3,2,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1, 0, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 2, 0, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE

};//Created by Yuan Lei

// BEGIN CUT HERE
int main() {
  TreeDistanceConstruction solver;
  solver.run_test(-1);

  std::cerr << "---------------------------" << std::endl;
  std::cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec." << std::endl;
  return 0;
}
// END CUT HERE
