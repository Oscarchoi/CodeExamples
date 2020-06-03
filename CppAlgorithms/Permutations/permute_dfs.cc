#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    int size = nums.size();
    if (!size)
      return res;

    vector<bool> check(size);
    vector<int> str;
    dfs(str, size, check, nums);
    return res;
  }
  vector<vector<int>> res;

  void dfs(vector<int> &str, int left, vector<bool> &check, vector<int> &nums) {
    if (left == 0)
      res.push_back(str);
    else {
      for (int i = 0; i < check.size(); ++i) {
        if (check[i])
          continue;
        str.push_back(nums[i]);
        check[i] = true;
        dfs(str, left - 1, check, nums);
        str.pop_back();
        check[i] = false;
      }
    }
  }
};