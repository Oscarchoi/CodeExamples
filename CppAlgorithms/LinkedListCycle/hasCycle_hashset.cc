#include <unordered_set>
/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    std::unordered_set<ListNode *> set;
    if (!head)
      return false;
    while (head->next) {
      if (set.find(head) != set.end())
        return true;
      else
        set.insert(head);
      head = head->next;
    }
    return false;
  }
};