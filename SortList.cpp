#include <iostream>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *sortList(ListNode *head) {
	    ListNode* dummyHead = new ListNode(0);
	    dummyHead->next = head;
	    if (head == NULL)
		    return head;
	    ListNode* ptr1 = head;
	    ListNode* ptr2 = dummyHead;
	    ListNode* ptr3 = head;
	    while (ptr1 != NULL) {
		    if (ptr1->val < dummyHead->next->val) {
			    ptr3 = ptr1->next;
			    dummyHead->next = ptr1;
			    ptr1->next = head;
			    ptr1 = ptr3;
		    } else 
		     {
			    while (ptr2->next &&
			           ptr2->next != ptr1 &&
			           ptr2->next->val <= ptr1->val) {
				    ptr2 = ptr2->next;
			    }
			    if (ptr2->next == ptr1) {
				    ptr1 = ptr1->next;
				    ptr2 = dummyHead;
				     
			    } else {
				    ptr3 = ptr1->next;
				    ptr1->next = ptr2->next;
				    ptr2->next = ptr1;
				    ptr1 = ptr3;
				    
				    ptr2 = dummyHead;
			    }
			    
		    }
	    }
            return dummyHead->next;
    }
};

void print(ListNode* head) {
	
	while (head) {
		std::cout << head->val << std::endl;
		head = head->next;
	}
}
int main() {
	ListNode* p0 = new ListNode(3);
	ListNode* p1 = new ListNode(2);
	ListNode* p2 = new ListNode(1);
	p0->next = p1;
	p1->next = p2;
	p2->next = NULL;
	Solution sol;
//	print(p0);
	print(sol.sortList(p0));
	return 0;
}
