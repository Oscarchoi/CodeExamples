#include <vector>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int res = nums[0];

    // Assume dp[index] = {max,min}
    // each dp[i] entry has max value and min value of
    // cumulative product subarray containing that indexed value
    // in this case use single pair of dp => high, low
    int high = res, low = res;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0)
        swap(high, low);
      high = max(nums[i], high * nums[i]);
      low = min(nums[i], low * nums[i]);

      res = max(res, high);
    }
    return res;
  }
};