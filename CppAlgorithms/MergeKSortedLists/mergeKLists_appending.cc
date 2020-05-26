#include <climits> // INT_MIN
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
    ListNode root(INT_MIN, lists[0]);
    ListNode *temp = &root;
    for (int i = 1; i < size; i++) {
      while (lists[i]) {
        if (!(temp->next)) {
          temp->next = lists[i];
          break;
        }
        if (lists[i]->val > temp->next->val) {
          temp = temp->next;
        } else {
          ListNode *ltmp = lists[i]->next;
          lists[i]->next = temp->next;
          temp->next = lists[i];
          lists[i] = ltmp;
        }
      }
      temp = &root;
    }
    return root.next;
  }
};