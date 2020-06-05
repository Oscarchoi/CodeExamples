#include <vector>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int walker = 0, runner = 0;
    while (true) {
      walker = nums[walker];
      runner = nums[nums[runner]];
      if (walker == runner)
        break;
    }
    int finder = 0;
    while (true) {
      walker = nums[walker];
      finder = nums[finder];
      if (walker == finder)
        break;
    }
    return walker;
  }
};