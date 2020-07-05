#include <vector>
using namespace std;

class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int row = mat.size(), col = mat[0].size();
    int res = 0;

    for (int i = 0; i < row; ++i) {
      int tmp = 0;
      for (int j = col - 1; j >= 0; --j) {
        if (mat[i][j])
          tmp += mat[i][j];
        else
          tmp = 0;
        mat[i][j] = tmp;
      }
    }

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        int cur = i, cmax = col;
        while (cur < row && mat[cur][j] > 0) {
          cmax = min(cmax, mat[cur][j]);
          res += cmax;
          cur++;
        }
      }
    }

    return res;
  }
};