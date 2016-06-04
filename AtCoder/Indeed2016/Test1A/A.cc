/*************************************************************************
	> File Name: A.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 28 May 2016 10:01:59 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  string inputString;
  cin >> inputString;
  set<string> answers;
  REP(i, inputString.size()) {
    REP(j, 4) {
      string newString = inputString;
      newString[i] = 'a' + j;
      sort(newString.begin(), newString.end());
      do {
        answers.insert(newString);
      }while (next_permutation(newString.begin(), newString.end()));
    }
  }
  for (auto &str: answers) {
    cout << str << endl;
  }
  return 0;
}

