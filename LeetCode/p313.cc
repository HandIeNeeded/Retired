/*************************************************************************
  > File Name: p313.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Mon 23 May 2016 08:09:15 PM CST
 *************************************************************************/
class Solution {
  public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      vector<int> uglyNumbers;
      vector<int> ptrPrimes(primes.size(), 0);
      uglyNumbers.push_back(1);
      while (uglyNumbers.size() < n) {
        vector<int> nextUglyNumbers;
        for (int i = 0; i < primes.size(); i++) nextUglyNumbers.push_back(uglyNumbers[ptrPrimes[i]] * primes[i]);
        auto idx = min_element(nextUglyNumbers.begin(), nextUglyNumbers.end()) - nextUglyNumbers.begin();
        uglyNumbers.push_back(nextUglyNumbers[idx]);
        for (int idx = 0; idx < primes.size(); idx++) {
          ptrPrimes[idx] = upper_bound(uglyNumbers.begin(), uglyNumbers.end(), uglyNumbers.back() / primes[idx]) - uglyNumbers.begin();
        }
      }
      return uglyNumbers.back();
    }
};

