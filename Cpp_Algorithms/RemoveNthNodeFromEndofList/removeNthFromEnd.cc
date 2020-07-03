/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!(head->next))
      return nullptr;
    ListNode *temp = head, *node = head;

    for (int cur = 0; cur < n; ++cur) {
      node = node->next;
    }

    if (!node)
      return head->next;

    while (node->next) {
      temp = temp->next;
      node = node->next;
    }

    temp->next = (temp->next)->next;
    return head;
  }
};