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
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode* dummyHead = (ListNode*) malloc(sizeof(ListNode));
        dummyHead->next = head;
        ListNode* ptr0 = NULL;
        ListNode* ptr1 = NULL;
        ListNode* ptr2 = NULL;
        ListNode* ptr3 = NULL;
        ptr0 = head;
        ptr1 = head->next;
        while (ptr1 != NULL) {
            if (ptr1->val < ptr0->val){
                ptr2 = dummyHead;
                ptr3 = dummyHead->next;
                while (ptr3 != NULL) {
                  std::cout << "eee" << std::endl;
                    if ((ptr3->val >= ptr1->val && ptr2 == dummyHead) ||
                        (ptr3->val >= ptr1->val && ptr2->val <= ptr1->val)){
                      std::cout << ptr3->val << std::endl;
                        ptr2->next = ptr1;
                        ptr0->next = ptr1->next;
                        ptr1->next = ptr3;
                        std::cout << "aaa" <<  ptr1->val << std::endl;
                        ptr1 = ptr0->next;
                        break;
                    } else {
                      std::cout << "ddd" << std::endl;
                        ptr2 = ptr2->next;
                        ptr3 = ptr3->next;
                    }
                }
                continue;
            }
            if (ptr1 == NULL) 
               break;
            ptr0 = ptr0->next;
            ptr1 = ptr1->next;
            std::cout << "bbb" << std::endl;
        }
        std::cout << "cc  "<< dummyHead->next->val << std::endl;
        return dummyHead->next;
    }
};

int main() {
  ListNode* p0 = (ListNode*) malloc(sizeof(ListNode));
  ListNode* p1 = (ListNode*) malloc(sizeof(ListNode));
  p0->val = 2;
  p0->next = p1;
  p1->val = 1;
  p1->next = NULL;
  Solution sol;
  ListNode* p2 = sol.insertionSortList(p0);
  std::cout << p2->val << " " << p2->next->val << std::endl;
  return 0;
}
