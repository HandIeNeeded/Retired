/*************************************************************************
  > File Name: p4.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Fri 13 May 2016 05:35:53 PM CST
 *************************************************************************/
class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int tot = nums1.size() + nums2.size();
      int L = (tot - 1) / 2;
      int lo = 0, hi = nums1.size();
      while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        int x = nums1[mid];
        int index = upper_bound(nums1.begin(), nums1.end(), x) - nums1.begin();
        int pos = upper_bound(nums2.begin(), nums2.end(), x) - nums2.begin();
        if (index + pos <= L) lo = mid;
        else hi = mid;
      }
      if (tot & 1) {
        int x = INT_MAX, y = INT_MAX;
        if (hi < nums1.size()) x = nums1[hi];
        int pos = upper_bound(nums2.begin(), nums2.end(), nums1[lo]) - nums2.begin();
        if (pos != nums2.end()) y = nums2[pos];
        return min(x, y);
      }
      else {
        int x = nums1[lo], y;
        if (lo + 1 < nums1.size()) y = nums1[lo + 1];
        int pos = lower_bound(nums2.begin(), nums2.end(), x) - nums2.begin();
        y = min(y, nums2[pos]);
        return (x + y) / 2.0;
      }
    }
}
