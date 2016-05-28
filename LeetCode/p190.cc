/*************************************************************************
  > File Name: p190.cc
  > Author: yuzhou627
  > Mail:   yuzhou627@gmail.com
  > Created Time: Sat 14 May 2016 06:33:05 PM CST
 *************************************************************************/
class Solution {
  public:
    uint8_t reverse(uint8_t x) {
      uint8_t answer = 0;
      for (int i = 0; i < 8; i++) {
        answer <<= 1;
        answer |= (x & 1);
        x >>= 1;
      }
      return answer;
    }

    uint8_t answer[1 << 8];

    uint32_t reverseBits(uint32_t x) {
      for (int i = 0; i < (1 << 8); i++) {
        answer[i] = reverse(i);
      }
      uint32_t result = 0;
      uint8_t magic = 255;
      for (int i = 0; i < 4; i++) {
        result <<= 8;
        result |= answer[x & magic];
        x >>= 8;
      }
      return result;
    }
};

