/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        int sum = 0;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        if (!l1 && !l2) {
            return NULL;
        } else 
        if (l1 && !l2) {
            return l1;
        } else 
        if (!l1 && l2) {
            return l2;
        } else {
            
            while (ptr1 && ptr2) {
                sum = ptr1->val + ptr2->val + carry;
                carry = sum / 10;
                ptr1->val = sum % 10;
                ptr2->val = ptr1->val;
                if (ptr1->next == NULL && ptr2->next == NULL) {
                    if (carry != 0) {
                        ListNode* tail = (ListNode*) malloc (sizeof(ListNode));
                        tail->val = carry;
                        tail->next = NULL;
                        ptr1->next = tail;
                    }
                    return l1;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            if (ptr1) {
                while (ptr1) {
                    sum = ptr1->val + carry;
                    carry = sum / 10;
                    ptr1->val = sum % 10;
                    if (!ptr1->next)
                        break;
                    ptr1 = ptr1->next;
                }
                if (carry != 0) {
                    ListNode* tail = (ListNode*) malloc (sizeof(ListNode));
                    tail->val = carry;
                    tail->next = NULL;
                    ptr1->next = tail;
                }
                return l1;
            } else 
            if (ptr2) {
                while (ptr2) {
                    sum = ptr2->val + carry;
                    carry = sum / 10;
                    ptr2->val = sum % 10;
                    if (!ptr2->next) 
                        break;
                    ptr2 = ptr2->next;
                }
                 if (carry != 0) {
                    ListNode* tail = (ListNode*) malloc (sizeof(ListNode));
                    tail->val = carry;
                    tail->next = NULL;
                    ptr2->next = tail;
                } 
                return l2;
            } 
        } 
    }
};
