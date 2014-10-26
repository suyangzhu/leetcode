#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// doulbe linked list for hash chaining
template<typename T>
class Node {
	Node(const T &other) {
		elem = new T(other);
		next = NULL;	
	}
	~Node() {
		delete elem;
		delete next;
	}
private:
	T *elem;
	Node* next;
};

template<typename T>
class List {

	List() {// create a dummy node as head
	}
	~List() {
	}
	void Insert(const T &elem) {
	}

	void Delete(const T &elem) {
	}
private:
	Node<T> *head;
	int size;
};

template<typename T>
class HashTable {

	HashTable (int size) : size(size) {}
	~HashTable() {}

	void Add(T &elem) {
	}

	bool Search(T &elem) {
	}

	void Remove(T & elem) {
	}
	int HashFunction(const T & elem) {
		int loc = (int) &elem % size;
		
		return loc > 0 ? loc : -loc;
	}
private:
	vector<List<T> *> table;
	int size;
};


