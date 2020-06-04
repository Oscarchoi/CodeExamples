#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto n : nums)
      sum += n;
    if (!sum || sum % 2)
      return false;

    sum = sum / 2;
    vector<int> dp(sum + 1, false);
    dp[0] = true;

    for (auto n : nums) {
      for (int i = sum; i >= n; --i) {
        if (dp[i - n])
          dp[i] = true;
      }
    }

    return dp[sum];
  }
};