#include <cstdio>
#include <cstdlib>
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) 
            return head;
        ListNode* largeHead = NULL;
        ListNode* lessHead = NULL;
        ListNode* large = NULL;
        ListNode* less = NULL;
        ListNode* ptr = NULL;
        ptr = head;
        while (ptr) {
            if (ptr->val < x) {
                if (less) {
                    less->next = ptr;
                    less = less->next;
                } else {
                    less = ptr;
                    lessHead = less;
                }
            } else {
                if (large) {
                    large->next = ptr;
                    large = large->next;
                } else {
                    large = ptr;
                    largeHead = large;
                }
            }
            std::cout << "aaa" << std::endl;
            ptr = ptr->next;
        }
        if (less) {
          less->next = largeHead;
          large->next = NULL;
          return lessHead;
        } else {
        }
        return lessHead;
    }
};

int main() {
  Solution sol;
  ListNode* root = (ListNode*) malloc (sizeof(ListNode));
  root->val = 1;
  root->next = NULL;
  sol.partition(root, 0);
  return 0;
}
