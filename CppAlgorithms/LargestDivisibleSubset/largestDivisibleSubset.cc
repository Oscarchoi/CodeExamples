#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int size = nums.size();
    if (size < 2)
      return nums;

    sort(nums.begin(), nums.end(), std::greater<int>());
    vector<pair<int, int>> dp(size, {1, -1});

    int idx = 0, tmp = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] % nums[i] == 0 && dp[j].first + 1 > dp[i].first) {
          dp[i].first = dp[j].first + 1;
          dp[i].second = j;
        }
      }
      if (dp[i].first > tmp) {
        tmp = dp[i].first;
        idx = i;
      }
    }

    vector<int> res;
    while (idx >= 0) {
      res.push_back(nums[idx]);
      idx = dp[idx].second;
    }
    return res;
  }
};