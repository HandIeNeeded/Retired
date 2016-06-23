/*************************************************************************
	> File Name: A.cc
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sat 11 Jun 2016 10:34:01 PM CST
*************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(0);
#ifdef HOME
  std::string file(__FILE__);
  freopen((file.substr(0, file.find('.')) + ".in").c_str(), "r", stdin);
  freopen((file.substr(0, file.find('.')) + ".out").c_str(), "w", stdout);
#endif
	stack<char> st;

	int T; string s;

	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> s;
		int score = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (!st.empty() && s[i] == st.top()) {
				score += 10;
				st.pop();
			}
			else st.push(s[i]);
		}
		score += 5 * st.size() / 2;
		while (!st.empty()) {
			st.pop();
		}
		printf("Case #%d: %d\n", t, score);
	}
	
	return 0;
}
