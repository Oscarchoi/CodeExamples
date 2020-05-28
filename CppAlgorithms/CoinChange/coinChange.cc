#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    if (!amount)
      return 0;

    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (auto n : coins) {
      for (int i = 0; i <= amount - n; ++i) {
        if (dp[i] >= 0)
          dp[i + n] = dp[i + n] > 0 ? min(dp[i + n], dp[i] + 1) : dp[i] + 1;
      }
    }
    return dp.back();
  }
};