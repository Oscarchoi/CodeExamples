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
  bool isPalindrome(ListNode *head) {
    ListNode *temp = head;
    int len = 0;
    while (temp) {
      len++;
      temp = temp->next;
    }
    if (len < 2)
      return true;

    int mid = len / 2;
    vector<int> bank(mid);
    int idx = 0;
    while (idx < mid) {
      bank[idx++] = head->val;
      head = head->next;
    }
    if (len % 2)
      head = head->next;
    while (head) {
      if (head->val != bank.back())
        return false;
      bank.pop_back();
      head = head->next;
    }
    return true;
  }
};