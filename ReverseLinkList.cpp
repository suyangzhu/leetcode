#include <iostream>
#include <cstdio>
#include <cstdlib>


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* ptr0 = NULL;
        ListNode* ptr1 = NULL;
        ListNode* ptr2 = NULL;
        ListNode* ptr3 = NULL;
        ListNode* mileStone = NULL;
        ListNode* firstNode = NULL;
        ListNode* lastNode = NULL;
        ListNode* dummyHead = (ListNode*) malloc(sizeof(ListNode));
        dummyHead->next = head;
        
        if (head == NULL) 
            return head;
        if (m == n)
            return head;
        int cnt = 1;
        ptr0 = dummyHead;
        while (cnt != m) {
            ptr0 = ptr0->next;
            cnt++;
        }
        mileStone = ptr0;
        ptr1 = ptr0->next;
        firstNode = ptr1;
        if (ptr1 == NULL)
            return head;
        ptr2 = ptr1->next;
        std::cout << "a" << std::endl; 
        while (cnt != n-1) {
            ptr3= ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
            cnt++;
        }
        ptr3 =  ptr2->next;
        ptr2->next = ptr1;
        mileStone->next = ptr2;
        firstNode->next = ptr3;
        return dummyHead->next;
    }
};

int main()  {
   ListNode* p0 = (ListNode*) malloc (sizeof(ListNode));
   ListNode* p1 = (ListNode*) malloc (sizeof(ListNode));
   p0->next = p1;
   p0->val = 3;
   p1->val = 5;
   p1->next = NULL;
   Solution sol;
   ListNode* head = sol.reverseBetween(p0, 1, 2);
   while (head) {
     std::cout << head->val << std::endl;
     head = head->next;
   }
   return 0;
}
