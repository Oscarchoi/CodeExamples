#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int size = tasks.size();
    if (size == 0 || n == 0)
      return size;

    vector<int> bank(26, 0);
    for (auto c : tasks)
      bank[c - 'A']++;

    sort(bank.begin(), bank.end(), greater<int>());
    int most = bank[0], count = 0;
    for (auto n : bank) {
      if (n == most)
        count++;
      else
        break;
    }

    int least = (n + 1) * (most - 1) + count;
    return max(least, size);
  }
};