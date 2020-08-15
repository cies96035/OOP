#pragma once
#include "iostream"
#include "Node.h"
class BST {
public:
	BST() {
		root = NULL;
	}
	void insert(Node* node);
    int search(int value,int mode);
	Node* getRoot();
private:
	Node* root;
};
