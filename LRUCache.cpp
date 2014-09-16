#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
class LRUCache{
public:
	int maxVolume;
	int cnt; 
	
	struct ListNode {
		ListNode *next;
		ListNode *prev;
		int key;
		ListNode(int key) : next(NULL), prev(NULL), key(key) {}
	};
	ListNode *dummyHead;
	ListNode *dummyTail;
	unordered_map<int, int> hashTable;
    	LRUCache(int capacity) {
	dummyHead = new ListNode(-1);
	dummyTail = new ListNode(-2);
	dummyTail->prev = dummyHead;
	dummyHead->next = dummyTail;
	maxVolume = capacity;
	cnt = 0;
    }
    
    int get(int key) {
	    if (hashTable.find(key) == hashTable.end()) 
		    return -1;
	    // find the key; 
	    ListNode* ptr = dummyHead->next;
	    while (ptr != dummyTail && ptr->key != key) ptr =  ptr->next;	 // shifting to node in list;
	    ListNode* tail = NULL;
            if (ptr == dummyTail->prev)
		 tail = ptr->prev;
	    if (ptr != dummyHead->next) { 	// double linked list insertion
		ListNode* oldPrev = ptr->prev;
		ListNode* oldNext = ptr->next;
	    	ptr->next = dummyHead->next;
	    	dummyHead->next->prev = ptr;
	    	ptr->prev = dummyHead;
	    	dummyHead->next = ptr;
		oldPrev->next = oldNext;
		oldNext->prev = oldPrev;
		if (tail) {dummyTail->prev = tail;tail->next = dummyTail;}
	    }
	    return hashTable[key];
    }
    
    void set(int key, int value) {
	   if (hashTable.find(key) == hashTable.end()) {	// not exsit. insert a new item.
		   hashTable[key] = value;			// insert into value;
		   ListNode *nextNode = dummyHead->next;
		   ListNode *node = new ListNode(key);
	           dummyHead->next = node;
	           node->prev = dummyHead;
	           node->next = nextNode;
	           nextNode->prev = node;
		   cnt++;
	   } else {
	   	 ListNode* ptr = dummyHead->next;
	   	 hashTable[key] = value; 
	   	 while (ptr != dummyTail && ptr->key != key) ptr =  ptr->next;	 // shifting to node in list;
		 ListNode *tail = NULL;
            	if (ptr == dummyTail->prev) {
		    tail = ptr->prev;
		}
		if (ptr != dummyHead->next) {
			ListNode* oldPrev = ptr->prev;
			ListNode* oldNext = ptr->next;
	    		ptr->next = dummyHead->next;
	    		dummyHead->next->prev = ptr;
	    		ptr->prev = dummyHead;
	    		dummyHead->next = ptr;
			oldPrev->next = oldNext;
			oldNext->prev = oldPrev;
			if (tail) {dummyTail->prev = tail; tail->next = dummyTail;} 	// set prev and next in pair
		}
	   } 		
	   // if cnt > max, remove tail.
	   if (cnt > maxVolume) {	// double linked list deletion.
		   hashTable.erase(dummyTail->prev->key);
		   ListNode* tmpTail = dummyTail->prev;
		   dummyTail->prev = tmpTail->prev;
		   tmpTail->prev->next = dummyTail;	// make sure to set prev and next in pair
		   delete tmpTail;
	   }
    }
};

int main() {
	LRUCache cache(2);	
	cache.set(2, 1);
	cache.set(2, 2);
	std::cout << cache.get(2) << std::endl;
	cache.set(1,1);
	cache.set(4,1);
	std::cout << cache.get(2) << std::endl;
//	std::cout << cache.get(3) << std::endl;
//	std::cout << cache.get(1) << std::endl;
	return 0;
}
