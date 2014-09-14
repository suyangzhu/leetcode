#include <iostream>
#include <cstdlib>
#include <climits>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *sortList(ListNode *head) {
	   if (head == NULL || head->next == NULL)
		   return head;
	   int len = 0;
	   ListNode* ptr = head;
	   while (ptr) {
		   len++;
		   ptr = ptr->next;
	   }
	   return Sort(&head, len);
    }
    // Since we are going to change the head. 
    // We must take **head as arguments.
    ListNode* Sort(ListNode** head, int len) {
	    // If length == 1 return head.
	    // The head must be shifted to next position after 
	    // every visiting. Must use **head here.
	    if (len == 1) {
		    ListNode* tmp = *head;
		    // Need to set every tail to be NULL 
		    // otherwise the program will not stop
		    (*head) = (*head)->next;
		    tmp->next = NULL;
		    return tmp;
	    }
	   // The head for left is different from the head for 
	   // the right. 
	    ListNode* left = Sort(head, len/2);
	    ListNode* right = Sort(head, len - len/2);
	    return Merge(left, right);
    }

    // Merge two linked list into one in an ascen
    ListNode* Merge(ListNode* left, ListNode* right) {
	    ListNode* head = new ListNode(-1);
	    ListNode* ptr = head;
	    while (left != NULL || right != NULL) {
		int firstVal = (left == NULL)? INT_MAX:left->val;
		int secondVal = (right == NULL)? INT_MAX:right->val;
		if (firstVal < secondVal) {
			ptr->next = left;
			left = left->next;
		} else {
			ptr->next = right;
			right = right->next;
		}
		ptr = ptr->next;
		std::cout << "ptr: "<< ptr << std::endl;
	    }
	    ptr->next = NULL;
	   ptr = head->next;
	   return ptr; 
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
	print(p0);
	print(sol.sortList(p0));
	return 0;
}
