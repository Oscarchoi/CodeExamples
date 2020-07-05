#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right) {
    int lmax = 0, rmax = 0;
    for (auto ant : left)
      if (ant > lmax)
        lmax = ant;
    for (auto ant : right)
      if (n - ant > rmax)
        rmax = n - ant;
    return max(lmax, rmax);
  }
};