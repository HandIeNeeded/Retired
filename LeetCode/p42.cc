/*************************************************************************
	> File Name: p42.cc
	> Author: yuzhou627
	> Mail:   yuzhou627@gmail.com
	> Created Time: Sun 22 May 2016 11:55:28 PM CST
*************************************************************************/
class Solution {
public:
  int GetAreaOfOneSide(vector<int> &height) {
    int sumArea = 0;
    for (int i = 0; i < height.size(); i++) {
      int j = i + 1;
      while (j < height.size() && height[j] <= height[i]) j++;
      for (int k = i + 1; k < j; k++) {
        sumArea += height[i] - height[k];
      }
      i = j - 1;
    }
    return sumArea;
  }

  int trap(vector<int>& height) {
    if (height.size() == 0) return 0;
    int maxHeight = *max_element(height.begin(), height.end());
    vector<int> leftPart, rightPart;
    int leftBound = 0, rightBound = height.size() - 1;
    for (int i = 0; i < height.size(); i++) {
      if (height[i] != maxHeight) {
        leftPart.push_back(height[i]);
      }
      else {
        leftBound = i;
        break;
      }
    }
    leftPart.push_back(maxHeight);
    for (int i = height.size() - 1; i >= 0; i--) {
      if (height[i] != maxHeight) {
        rightPart.push_back(height[i]);
      }
      else {
        rightBound = i;
        break;
      }
    }
    rightPart.push_back(maxHeight);
    int sumArea = GetAreaOfOneSide(leftPart) + GetAreaOfOneSide(rightPart);
    for (int i = leftBound + 1; i < rightBound; i++) sumArea += maxHeight - height[i];
    return sumArea;
  }
};
