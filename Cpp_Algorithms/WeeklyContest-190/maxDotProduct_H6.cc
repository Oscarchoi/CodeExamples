/**
 * 1458. Max Dot Product of Two Subsequences
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n));

    dp[0][0] = nums1[0] * nums2[0];
    for (int j = 1; j < n; ++j)
      dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);

    for (int i = 1; i < m; ++i) {
      dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
      for (int j = 1; j < n; ++j) {
        dp[i][j] =
            max(dp[i - 1][j],
                max(dp[i][j - 1], dp[i - 1][j - 1] > 0
                                      ? dp[i - 1][j - 1] + nums1[i] * nums2[j]
                                      : nums1[i] * nums2[j]));
      }
    }

    /* for check */
    // for(auto v:dp){
    //   for(auto n:v) cout<<n<<", ";
    //   cout<<endl;
    // }

    return dp[m - 1][n - 1];
  }
};