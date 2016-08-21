/*************************************************************************
  >         File: p6.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Wed 17 Aug 2016 11:03:04 PM CST
*************************************************************************/
#include <bits/stdc++.h>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;
    std::string ans[numRows];
    int row = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (row < numRows) ans[row] += c;
      else ans[2 * numRows - 2 - row] += c;
      row++;
      if (row == 2 * numRows - 2) row = 0;
    }
    std::string res;
    for (int i = 0; i < numRows; i++) res += ans[i];
    return res;
  }
};
