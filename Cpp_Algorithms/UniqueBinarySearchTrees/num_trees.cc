#include <vector>
using namespace std;

/*
 * The number of unique BST(Binary Search Tree) is
 * DP(n) = DP(0)* DP(n-1) + DP(1) * DP(n-2) + ... + DP(n-1)*DP(0)
 *
 * For example, in case that there are 1, 2, 3, ..., M, ..., N nodes,
 * root node of M may have left child which could be 1 ~ M-1
 * and right child which could be M+1 ~ N
 * Therefore, number of unique bst for root M is DP(M-1) * DP(N-M-1)
 *
 * @Oscarchoi
 */

class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      int mid = i / 2;
      for (int j = 0; j < mid; ++j)
        dp[i] += 2 * dp[j] * dp[i - 1 - j];
      if (i % 2)
        dp[i] += dp[mid] * dp[mid];
    }
    return dp[n];
  }
};
