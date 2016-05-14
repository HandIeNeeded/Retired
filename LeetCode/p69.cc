/*************************************************************************
	> File Name: p69.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Thu 12 May 2016 05:10:29 PM CST
*************************************************************************/
#include <cmath>
class Solution {
public:
  int mySqrt(int x) {
    if (x < 0) return INT_MIN;
    return int(sqrt(x + 0.5));
  }
};
