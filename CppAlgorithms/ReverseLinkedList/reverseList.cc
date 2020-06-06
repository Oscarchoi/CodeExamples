/* Definition for singly-linked list.  */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  /* Iterative Approach */
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return head;

    ListNode *cur = head, *res = head;
    while (cur->next != nullptr) {
      ListNode *temp = cur->next;
      cur->next = temp->next;
      temp->next = res;
      res = temp;
    }
    return res;
  }

  /* Recursive Approach
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *tail = head;
    while (tail->next != nullptr)
      tail = tail->next;
    helper(head, head->next);
    return tail;
  }

  ListNode *helper(ListNode *first, ListNode *second) {
    if (second->next != nullptr)
      second = helper(second, second->next);
    second->next = first;
    first->next = nullptr;
    return first;
  }
  */
};
