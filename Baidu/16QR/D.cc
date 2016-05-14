/*************************************************************************
	> File Name: D.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sat 14 May 2016 01:15:49 PM CST
*************************************************************************/
#include <iostream>
#include <algorithm>
#include <map>
typedef long long LL;
#define REP(i, a) REPP(i, 0, (a) - 1)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int t, ca = 1;
  cin >> t;
  map<string, int> mp;
  while (t--) {
    string buffer;
    cin >> buffer;
    sort(buffer.begin(), buffer.end());
    cout << mp[buffer] << endl;
    mp[buffer]++;
  }
  return 0;
}



