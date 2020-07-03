#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int countTriplets(vector<int> &arr) {
    unordered_map<int, vector<int>> bank;
    bank[0].push_back(-1);
    int ans = 0, cur = 0;
    for (int i = 0, size = arr.size(); i < size; ++i) {
      cur ^= arr[i]; // accumulating the xor result
      for (auto prev : bank[cur]) {
        // if cur was found before, it means
        // xor of (prev, i] values = 0
        // therefore, 'i - prev - 1' of subset could be added
        ans += (i - prev - 1);
      }
      bank[cur].push_back(i);
    }
    return ans;
  }
};