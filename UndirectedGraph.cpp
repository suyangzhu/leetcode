#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };
class Solution {
public:
    UndirectedGraphNode *deepCopy(UndirectedGraphNode* node, map<UndirectedGraphNode*, UndirectedGraphNode*>& nodeMap) {
        int i;
        if (node == NULL) 
            return NULL;
        if (nodeMap.find(node) == nodeMap.end()) {
            UndirectedGraphNode* dupNode = new UndirectedGraphNode(node->label);
            nodeMap[node] = dupNode;
            for (i = 0; i < node->neighbors.size(); i++) {
                UndirectedGraphNode* successor = deepCopy(node->neighbors[i], nodeMap);
                dupNode->neighbors.push_back(successor);
            }
            return dupNode;
        } else {
            return nodeMap[node];
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) 
            return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> nodemap;
        return deepCopy(node, nodemap);
    }
};

int main() {
  UndirectedGraphNode* node = (UndirectedGraphNode*) malloc (sizeof(UndirectedGraphNode));
  node->label = -1;
//  node->neighbors.push_back(node);
  Solution sol;
  UndirectedGraphNode* clone = sol.cloneGraph(node);
  std::cout << clone->label << std::endl;
  return 0;
}
