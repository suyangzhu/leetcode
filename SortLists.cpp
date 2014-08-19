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
    ListNode *nextLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if (size == 0)
            return NULL;
        int i;
        int index = 0;
        std::cout << size << std::endl;
        ListNode* next = NULL;
        std::cout << "++++" << std::endl;
        for (i = 0; i < size; i++) {
            if (next == NULL && lists[i] != NULL) {
                index = i;
                next = lists[i];
            } else 
            if (lists[i] == NULL) {
                std::cout << "aa"  << std::endl;     
                continue;
            } else
            if (lists[i]->val < next->val){
              std::cout << "BB" << std::endl;
                next = lists[i];
                index = i;
            }
        }
        std::cout << "dd" << std::endl;
        if (next != NULL) {
            lists[index] = lists[index]->next;
        } 
        std::cout << "---" << std::endl;
        return next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if (size == 0)
            return NULL;
        int i, j;
        ListNode* head = NULL;
        ListNode* ptr0 = NULL;
        ListNode* ptr1 = NULL;
        head = nextLists(lists);
        ptr0 = head;
        if (head == NULL)
            return head;
        while (1) {
            ptr1 = nextLists(lists);
            if (ptr1) {
                ptr0->next = ptr1;
                ptr0 = ptr1;
            } else {
                break;
            }
        }
        ptr0->next = NULL;
        return head;
    }
};

int main()  {
  ListNode* p0 = new ListNode(1);
  vector<ListNode*> vec;
  vec.push_back(NULL);
  vec.push_back(p0);
  Solution sol;
  ListNode* head = sol.mergeKLists(vec);
  std::cout << head->val << std::endl;
}
