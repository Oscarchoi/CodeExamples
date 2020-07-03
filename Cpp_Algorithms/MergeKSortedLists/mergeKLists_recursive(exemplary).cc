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

    while (size > 1) {
      for (int i = 0; i < size / 2; ++i) {
        lists[i] = mergeTwoLists(lists[i], lists[size - 1 - i]);
      }
      size = (size + 1) / 2;
    }

    return lists.front();
  }

  ListNode *mergeTwoLists(ListNode *lhs, ListNode *rhs) {
    if (!lhs)
      return rhs;
    else if (!rhs)
      return lhs;

    if (lhs->val < rhs->val) {
      lhs->next = mergeTwoLists(lhs->next, rhs);
      return lhs;
    } else {
      rhs->next = mergeTwoLists(lhs, rhs->next);
      return rhs;
    }
  }
};