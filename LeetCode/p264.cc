/*************************************************************************
  > File Name: p264.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Mon 23 May 2016 07:41:41 PM CST
 *************************************************************************/
class Solution {
  public:
    int nthUglyNumber(int n) {
      vector<int> uglyNumbers;
      vector<int> ptrPrimes(3, 0), primes;
      primes.push_back(2), primes.push_back(3), primes.push_back(5);
      uglyNumbers.push_back(1);
      while (uglyNumbers.size() < n) {
        vector<int> nextUglyNumbers;
        for (int i = 0; i < 3; i++) nextUglyNumbers.push_back(uglyNumbers[ptrPrimes[i]] * primes[i]);
        auto idx = min_element(nextUglyNumbers.begin(), nextUglyNumbers.end()) - nextUglyNumbers.begin();
        uglyNumbers.push_back(nextUglyNumbers[idx]);
        for (int idx = 0; idx < 3; idx++) while (uglyNumbers[ptrPrimes[idx]] * primes[idx] <= uglyNumbers.back()) ptrPrimes[idx]++;
      }
      return uglyNumbers.back();
    }
};
