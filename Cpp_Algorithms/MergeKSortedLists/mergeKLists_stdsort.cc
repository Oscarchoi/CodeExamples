#include <algorithm>
#include <functional> // std::less
#include <vector>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int size = lists.size();
    if (!size)
      return nullptr;
    vector<int> nums;
    for (auto list : lists) {
      while (list) {
        nums.push_back(list->val);
        list = list->next;
      }
    }
    std::sort(nums.begin(), nums.end(), less<int>());
    ListNode *root = nullptr, *temp = nullptr;
    for (auto n : nums) {
      if (!root)
        root = temp = new ListNode(n);
      else {
        temp->next = new ListNode(n);
        temp = temp->next;
      }
    }
    return root;
  }
};