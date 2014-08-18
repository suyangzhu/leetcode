#include <iostream>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
class Solution {
public:
    RandomListNode* deepcopy(RandomListNode* head, map<RandomListNode*, RandomListNode*>& nodeMap) {
        if (head == NULL) 
            return NULL;
        RandomListNode* node = (RandomListNode*) malloc(sizeof(RandomListNode));
        node->label = head->label;
        if (head->next && nodeMap.find(head->next) == nodeMap.end()) {
            nodeMap[head->next] = NULL;
            node->next = deepcopy(head->next, nodeMap);
            nodeMap[head->next] = node->next;
        } else 
        if (head->next) {
            node->next = nodeMap.find(head->next)->second;
        } else {
            node->next = NULL;
        }
        if (head->random && nodeMap.find(head->random) == nodeMap.end()) {
            nodeMap[head->random] = NULL;
            node->random = deepcopy(head->random, nodeMap);
            nodeMap[head->random]= node->random;
        } else 
        if (head->random) {
            node->random = nodeMap.find(head->random)->second;
        } else {
            node->random = NULL;
        }
        return node;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) 
            return NULL;
        map<RandomListNode*, RandomListNode*> nodemap;
        return deepcopy(head, nodemap);
    }
};

int main() { 
  RandomListNode* p0 = (RandomListNode*) malloc (sizeof(RandomListNode));

  RandomListNode* p1 = (RandomListNode*) malloc (sizeof(RandomListNode));
  RandomListNode* p2 = (RandomListNode*) malloc (sizeof(RandomListNode));

  p0->label = 0;
  p1->label = 1;
  p2->label = 2;
  p0->random = p1;
  p0->next = p1;
  p1->random = NULL;
  p1->next = p2;
  p2->next = NULL;
  p2->random = p0;

  Solution sol;
  RandomListNode* result = sol.copyRandomList(p0);
  return 0;

}
