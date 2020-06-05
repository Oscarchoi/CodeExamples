#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> bank;
  int total = 0, sz = 0;

public:
  Solution(vector<int> &w) {
    sz = w.size();
    bank.resize(sz);
    for (int i = 0; i < sz; i++) {
      total += w[i];
      bank[i] = total - 1;
    }
  }
  int pickIndex() {
    int n = rand() % total;
    int i = 0, f = sz - 1;
    while (i < f) {
      int mid = (i + f) / 2;
      if (n < bank[mid])
        f = mid;
      else if (bank[mid] < n)
        i = mid + 1;
      else
        return mid;
    }
    return f;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */