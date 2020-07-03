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
    ListNode *root = nullptr, *temp = nullptr;
    while (true) {
      int index = -1;
      for (int i = 0, size = lists.size(); i < size; ++i) {
        if (!lists[i])
          continue;
        if (index < 0 || lists[i]->val < lists[index]->val) {
          index = i;
        }
      }

      if (index < 0)
        break;
      if (root) {
        temp = temp->next = lists[index];
        lists[index] = temp->next;
      } else {
        temp = root = lists[index];
        lists[index] = lists[index]->next;
      }
    }

    return root;
  }
};