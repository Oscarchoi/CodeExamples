/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *walker = head, *runner = head;

    while (runner && runner->next) {
      walker = walker->next;
      runner = runner->next->next;
      if (walker == runner)
        return true;
    }
    return false;
  }
};