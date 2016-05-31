/*************************************************************************
	> File Name: C.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 29 May 2016 05:32:36 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

bool dfs(int pos, int num, const string& str, vector<string>& answer) {
  if (num == 1) {
    answer.push_back(str.substr(pos));
    for (int i = 0; i < answer.size(); i++) {
      if (answer[i].size() == 0) {
        answer.pop_back();
        return 0;
      }
      for (int j = i + 1; j < answer.size(); j++) {
        if (answer[i] == answer[j]) {
          answer.pop_back();
          return 0;
        }
      }
    }
    return 1;
  }
  else {
    for (int i = pos; i < str.size(); i++) {
      answer.push_back(str.substr(pos, i - pos + 1));
      if (dfs(i + 1, num - 1, str, answer)) {
        return 1;
      }
      else {
        answer.pop_back();
      }
    }
    return 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  int t, ca = 1;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int k;
    cin >> k;
    vector<string> answer;
    int good = 0;
    if (k * (k + 1) / 2 <= str.size()) {
      good = 1;
      int now = 0;
      REP(i, k - 1) {
        answer.push_back(str.substr(now, i + 1));
        now += i + 1;
      }
      answer.push_back(str.substr(now));
    }
    else {
      good = dfs(0, k, str, answer);
    }
    if (good) {
      cout << "YES" << endl;
      for (auto &str: answer) {
        cout << str << endl;
      }
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

