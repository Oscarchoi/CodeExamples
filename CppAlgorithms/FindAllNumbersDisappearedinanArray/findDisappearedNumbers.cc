#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int sz = nums.size();
    int i = 0;
    while (i < sz) {
      int idx = nums[i] - 1;
      if (idx == i)
        i++;
      else if (nums[idx] == nums[i])
        i++;
      else
        swap(nums[idx], nums[i]);
    }

    vector<int> res;
    for (int i = 0; i < sz; i++) {
      if (i != nums[i] - 1)
        res.push_back(i + 1);
    }

    return res;
  }
};