#include <climits>
#include <vector>
using namespace std;

class Solution {
private:
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    vector<int> node(n, INT_MAX);
    node[src] = 0;

    K++;
    while (K--) {
      vector<int> temp(node);
      for (auto &pair : flights) {
        if (temp[pair[0]] == INT_MAX)
          continue;
        node[pair[1]] = min(temp[pair[0]] + pair[2], node[pair[1]]);
      }
    }
    return node[dst] == INT_MAX ? -1 : node[dst];
  }
};