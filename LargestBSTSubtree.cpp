#include <cstdio>
#include <cstdlib>
#include <iostream>

int FindLargestBSTSubtree(BinaryTee *p, int &min, int &max, int &maxNodes, BinaryTree *& largestBST) {

	if (!p) return 0;
	bool isBST = true;
	int leftNodes = FindLargestBSTSubtree (
			p->left, min, max, maxNodes, largestBST);
	int currMin = (leftNodes == 0) ? p->data : min;
	if (leftNodes == -1 ||
	    leftNodes != 0 && p->data <= max) {
		isBST = false;
	}

	int rightNodes = FindLargestBSTSubtree (
			p->right, min, max, maxNodes, largestBST);
	int currMax = (rightNodes == 0) ? p->data: max;
	if (rightNodes == -1 ||
	    rightNodes != 0 && p->data >= min) {
		isBST = false;
	}
	if (isBST) {
		min = currMin;
		max = currMax;
		int total = leftNodes + rightNodes + 1;
		if (total > maxNodes) {
			maxNodes = total;
			largestBST = p;
		}
		return total;
	} else {
		return -1;
	}
}

BinaryTree* Find (BinaryTree * root) {
	BinaryTree *largest = NULL;
	int min;
	int max;
	int maxNodes = INT_MIN;
	FindLargestBSTSubtree(root, min, max, maxNodes, largest);
	return largest;
}
