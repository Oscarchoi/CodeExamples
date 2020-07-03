#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    int sz = nums.size();

    unordered_map<int, int> count;
    for (auto n : nums)
      ++count[n];

    vector<vector<int>> buckets(sz + 1);
    for (auto &pair : count)
      buckets[pair.second].push_back(pair.first);

    vector<int> res;
    for (int i = sz; i > 0; i--) {
      for (auto &pair : buckets[i]) {
        res.push_back(pair);
        if (res.size() == k)
          return res;
      }
    }

    return res;
  }
};