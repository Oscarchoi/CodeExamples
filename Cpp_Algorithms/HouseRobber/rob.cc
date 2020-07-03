#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.empty())
      return 0;
    int sz = nums.size();
    if (sz == 1)
      return nums[0];

    vector<int> dp(sz);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < sz; i++)
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

    return dp[sz - 1];
  }
};