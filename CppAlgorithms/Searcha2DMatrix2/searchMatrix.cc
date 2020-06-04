#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    int r = matrix.size();
    if (r == 0)
      return false;
    int c = matrix[0].size();
    if (c == 0)
      return false;

    for (int i = 0; i < c; i++)
      if (matrix[0][i] > target)
        c = i;
    for (int i = 0; i < r; i++)
      if (matrix[i][0] > target)
        r = i;

    int front = 0;
    for (int i = r - 1; i >= 0; --i) {
      if (matrix[i][c - 1] < target)
        break;

      int end = c - 1;
      while (front <= end) {
        int mid = (front + end) / 2;
        if (matrix[i][mid] == target)
          return true;
        else if (matrix[i][mid] > target)
          end = mid - 1;
        else
          front = mid + 1;
      }
      front--;
    }
    return false;
  }
};