#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    res.push_back({});
    for (auto n : nums) {
      for (int i = res.size() - 1; i >= 0; i--) {
        vector<int> tmp(res[i]);
        tmp.push_back(n);
        res.push_back(tmp);
      }
    }
    return res;
  }
};