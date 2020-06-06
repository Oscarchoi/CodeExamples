#include <vector>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int head = 0, tail = height.size() - 1, depth = 0, score = 0;

    while (head < tail) {
      while (height[head] <= depth && head < tail) {
        score += depth - height[head];
        ++head;
      }
      while (height[tail] <= depth && head <= tail) {
        score += depth - height[tail];
        --tail;
      }
      ++depth;
    }
    return score;
  }
};