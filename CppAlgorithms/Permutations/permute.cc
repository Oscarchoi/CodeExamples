#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    int size = nums.size();
    if (!size)
      return res;

    vector<int> str{nums[0]};
    res.emplace_back(std::move(str));
    for (int i = 1; i < size; ++i) {
      int pz = res.size();
      for (int j = 0; j < pz; j++) {
        int len = res[j].size();
        for (int k = 0; k < len; k++) {
          vector<int> temp = res[j];
          temp.insert(temp.begin() + k, nums[i]);
          res.emplace_back(std::move(temp));
        }
        res[j].push_back(nums[i]);
      }
    }
    return res;
  }
};