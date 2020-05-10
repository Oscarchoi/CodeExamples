// Brute force
#include <vector>
using namespace std;

class Solution {
public:
  int countTriplets(vector<int> &arr) {
    int res = 0;
    for (int i = 0, size = arr.size(); i < size; ++i) {
      int left = arr[i];
      for (int j = i + 1; j < size; ++j) {
        int right = arr[j];
        if (left == right)
          res++;
        for (int k = j + 1; k < size; ++k) {
          right ^= arr[k];
          if (left == right)
            res++;
        }
        left ^= arr[j];
      }
    }
    return res;
  }
};