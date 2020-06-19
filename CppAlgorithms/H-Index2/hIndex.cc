#include <vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int size = citations.size();
    int l = 0, r = size - 1;

    int res = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (citations[mid] <= size - mid) {
        res = max(res, citations[mid]);
        l = mid + 1;
      } else {
        res = max(res, size - mid);
        r = mid - 1;
      }
    }
    return res;
  }
};