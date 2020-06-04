#include <vector>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int size = nums.size();
    int res = 0;
    int index = 0, end = 0;
    while (end < size - 1) {
      int f = end;
      while (index <= f) {
        end = max(end, index + nums[index++]);
      }
      res++;
    }
    return res;
  }
};