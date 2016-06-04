/*************************************************************************
	> File Name: B.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 04 Jun 2016 07:10:34 PM CST
*************************************************************************/
#include <bits/stdc++.h>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

string GetNextStr(const string& str) {
  int position = str[0] - '0';
  if (position == 1) return str;
  return str.substr(1, position - 1) + str[0] + str.substr(position);
}

int main() {
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
#endif
  string inputString;
  cin >> inputString;
  unordered_map<string, int> historyStrs;
  int circle = 0, start = -1;
  string nowStr = inputString;
  LL times;
  cin >> times;
  vector<string> cacheStrs;
  historyStrs[nowStr] = 0;
  cacheStrs.push_back(nowStr);
  while (true) {
    nowStr = GetNextStr(nowStr);
    circle++;
    if (historyStrs.count(nowStr)) {
      start = historyStrs[nowStr];
      circle -= historyStrs[nowStr];
      break;
    }
    else {
      historyStrs[nowStr] = circle;
      cacheStrs.push_back(nowStr);
    }
  }
  if (times < start) {
    cout << cacheStrs[times] << endl;
  }
  else {
    times -= start;
    times %= circle;
    cout << cacheStrs[start + times] << endl;
  }
  cerr << "Just for test. :)" << endl;
  return 0;
}


