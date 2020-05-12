#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;

    int size = nums.size();
    if (size < 3)
      return res;

    std::sort(nums.begin(), nums.end());
    auto getNext = [&nums, &size](int &i) {
      int tmp = nums[i];
      while (++i < size && nums[i] == tmp)
        ;
    };

    for (int i = 0; i < size - 2; ++i) {
      if (i && nums[i] == nums[i - 1])
        continue;

      int n = nums[i];
      int j = i + 1, k = size - 1;
      while (j < k) {
        int temp = n + nums[j] + nums[k];
        if (temp > 0)
          --k;
        else if (temp < 0)
          ++j;
        else {
          res.push_back({nums[i], nums[j], nums[k]});
          getNext(j);
          // res에 새로운 값이 추가되는 경우에만 같은 j을 건너뛰면 됨
          // j만 건너뛴다면 k에 대해서는 굳이 수행할 필요 없음
          --k;
        }
      }
    }
    return res;
  }
};