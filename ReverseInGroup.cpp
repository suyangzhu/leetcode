#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void reverse(ListNode* start, ListNode* end) {
        ListNode* ptr0 = NULL;
        ListNode* ptr1 = NULL;
        ListNode* ptr2 = NULL;
        ListNode* init = NULL;
        ptr0 = start->next;
        ptr1 = ptr0->next;
        init = ptr0;
        while(ptr1 != end) {
            ptr2 = ptr1->next;
            ptr1->next = ptr0;
            ptr0 = ptr1;
            ptr1 = ptr2;
        }
        start->next = ptr1;
        init->next = ptr1->next;
        ptr1->next = ptr0;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2 || head == NULL)
            return head;
            
        int cnt = 1;
        ListNode* dummyHead = (ListNode*) malloc(sizeof(ListNode));
        dummyHead->next = head;
        ListNode* ptr0 = NULL;
        ListNode* ptr1 = NULL;
        ptr0 = dummyHead;
        ptr1 = ptr0->next;
        while (ptr1) {
            while (cnt != k) {
                ptr1 = ptr1->next;
                if (ptr1 == NULL)
                    return dummyHead->next;
                cnt++;
            }
            ListNode* tmpNext = ptr0->next;
            reverse(ptr0, ptr1);
            ptr0 = tmpNext;
            ptr1 = ptr0->next;
            cnt = 1;
        }
        ListNode* tmp = dummyHead->next;
        return dummyHead->next;
    }
};

int main() {
  Solution sol; 
  ListNode* p0 = (ListNode*) malloc(sizeof(ListNode));
  ListNode* p1 = (ListNode*) malloc(sizeof(ListNode));
  ListNode* p2 = (ListNode*) malloc(sizeof(ListNode));
  p0->val = 1; 
  p1->val = 2;
  p2->val = 3;
  p0->next = p1;
  p1->next = p2;
  p2->next = NULL;
  ListNode* head = sol.reverseKGroup(p0, 3);
  while (head != NULL) {
    std::cout << head->val << std::endl;
    head = head->next;
  }
  return 0;

}
