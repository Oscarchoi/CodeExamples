#include <vector>
using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int sz = nums.size();

    int i = 0;
    while (i + 1 < sz && nums[i + 1] >= nums[i])
      i++;
    for (int j = i + 1; j < sz; j++) {
      while (i >= 0 && nums[j] < nums[i])
        i--;
      if (i < 0)
        break;
    }

    int k = sz - 1;
    while (k > 0 && nums[k] >= nums[k - 1])
      k--;
    for (int j = k - 1; j >= 0; j--) {
      while (k < sz && nums[k] < nums[j])
        k++;
      if (k >= sz)
        break;
    }

    return i >= k ? 0 : k - i - 1;
  }
};