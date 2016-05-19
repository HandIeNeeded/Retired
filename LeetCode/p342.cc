/*************************************************************************
	> File Name: p342.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Mon 16 May 2016 06:50:13 PM CST
*************************************************************************/
#include <cmath>
class Solution {
public:
  bool isPowerOfFour(int x) {
    if (x <= 0) return 0;
    if (x & (x - 1)) return 0;
    int root = sqrt(x + 0.5);
    return root * root == x;
  }
};
