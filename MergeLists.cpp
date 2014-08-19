#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *twoMerge(ListNode* ptr0, ListNode* ptr1) {
      if (!ptr0 && !ptr1) {
        return NULL;
      } else 
      if (!ptr0) {
        return ptr1;
      } else 
      if (!ptr1) {
        return ptr0;
      } else {
        ListNode* head = NULL;
        ListNode* ptr = NULL;
        if (ptr0->val < ptr1->val) {
          head = ptr0; 
          ptr0 = ptr0->next;
        } else {
          head = ptr1;
          ptr1 = ptr1->next;
        }
        ptr = head;
        while (ptr0 && ptr1) {
          if (ptr0->val < ptr1->val) {
            ptr->next = ptr0;
            ptr = ptr->next;
            ptr0 = ptr0->next;
          } else {
            ptr->next = ptr1;
            ptr = ptr->next;
            ptr1 = ptr1->next;
          }
        }
        while (ptr0) {
          ptr->next = ptr0;
          ptr = ptr->next;
          ptr0 = ptr0->next;
        }
        while (ptr1) {
          ptr->next = ptr1;
          ptr = ptr->next;
          ptr1 = ptr1->next;
        }
        ptr->next = NULL;
        return head;
      }
    }
    ListNode *splitMerge(vector<ListNode *> &lists, int start, int end) {
      if (end - start < 1)
        return NULL;
      if (end - start == 1) 
        return lists[start];
      int mid = (start+end)/2;
      
      ListNode* ptr1 = splitMerge(lists, start, mid);
      ListNode* ptr2 = splitMerge(lists, mid, end);
      return twoMerge(ptr1, ptr2); 
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
      return splitMerge(lists, 0, lists.size());
    }
};

int main()  {
  ListNode* p0 = new ListNode(1);
  ListNode* p1 = new ListNode(3);
  ListNode* p2 = new ListNode(5);
  ListNode* pp0 = new ListNode (2);
  ListNode* pp1 = new ListNode(4);
  ListNode* pp2 = new ListNode(5);
  ListNode* ppp0 = new ListNode(-2);
  ListNode* ppp1 = new ListNode(8);
  ListNode* ppp2 = new ListNode(12);
  ListNode* ppp3 = new ListNode(14);
  p0->next = p1;
  p1->next = p2;
  p2->next = NULL;
  pp0->next = pp1;
  pp1->next = pp2;
  pp2->next = NULL;
  ppp0->next = ppp1;
  ppp1->next = ppp2;
  ppp2->next = ppp3;
  ppp3->next = NULL;
  
  vector<ListNode*> vec;
  vec.push_back(NULL);
  vec.push_back(NULL);
  vec.push_back(ppp0);
  vec.push_back(pp0);
  vec.push_back(NULL);
  vec.push_back(p0);
  Solution sol;
  ListNode* head = sol.mergeKLists(vec);
  while (head) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
  return 0;
}
