/*************************************************************************
  >         File: p384.cc
  >       Author: Riho.Yoshioka
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Wed 17 Aug 2016 10:51:12 PM CST
*************************************************************************/
class Solution {
private:
    std::vector<int> array;
public:
    Solution(vector<int> nums) {
      array = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
      return array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
      std::vector<int> tmp = array;
      for (int i = tmp.size() - 1; i > 0; i--) {
        swap(tmp[i], tmp[rand() % (i + 1)]);
      }
      return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
