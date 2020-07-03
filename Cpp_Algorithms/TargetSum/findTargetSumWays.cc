#include <vector>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    if (S > 1000 || S < -1000)
      return 0;
    return findSubSumWays(nums, nums.size() - 1, S);
  }

  int findSubSumWays(vector<int> &nums, int end, int S) {
    if (end == 0) {
      int res = 0;
      if (nums[0] == S)
        res++;
      if (nums[0] == -S)
        res++;
      return res;
    }
    return findSubSumWays(nums, end - 1, S + nums[end]) +
           findSubSumWays(nums, end - 1, S - nums[end]);
  }
};