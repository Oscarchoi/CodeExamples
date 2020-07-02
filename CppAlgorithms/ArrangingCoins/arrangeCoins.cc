#include <cmath>

class Solution {
public:
  int arrangeCoins(int n) {
    long N = n;
    int i = 1, f = sqrt((long)2 * n), res = 0;
    while (i <= f) {
      long mid = (i + f) / 2;
      if (mid * (mid + 1) / 2 <= N) {
        res = mid;
        i = mid + 1;
      } else
        f = mid - 1;
    }
    return res;
  }
};