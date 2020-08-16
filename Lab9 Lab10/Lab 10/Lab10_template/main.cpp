#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "BST.cpp"
#include "Node.h"
#include "Node.cpp"

using namespace std;

void inOrderTraverse(Node* root) {
	// Inorder traverse all the node and print them out
	if(!root)
		return;

	//inorder
	inOrderTraverse(root->getLchild());
	cout<<root->getValue()<<' ';
	inOrderTraverse(root->getRchild());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ifstream input("input.txt");
	if(!input)//open failed
	{
		cout<<"cannot open input.txt\n";
		return 1;
	}

	int element_amounts,input_value;
	string implement;
	BST binary_search_tree;

	//insert first elememt_amounts nodes
	input >> element_amounts;
	for(int i=0;i<element_amounts;i++)
	{
		input >> input_value;
		Node *n=new Node(input_value);
		binary_search_tree.insert(n);
	}

	while(input>>implement)
	{
		//create a new node with value and insert
		if(implement=="i")
		{
			input >> input_value;
			Node *n=new Node(input_value);
			binary_search_tree.insert(n);
		}

		//search for a value's node position
		else if(implement=="sp")
		{
			input >> input_value;
			cout<<binary_search_tree.search(input_value, 1)<<'\n';
		}

		//search for a node position's value
		else if(implement=="sn")
		{
			input >> input_value;
			cout<<binary_search_tree.search(input_value, 2)<<'\n';
		}

		//print the binary tree by inorder, that is, sort of elements
		else if(implement=="p")
		{
			inOrderTraverse(binary_search_tree.getRoot());
			cout<<'\n';
		}

		//error implement
		else
			cout<<"undefine implement\n";
	}

	cout<<flush;
	system("pause");
	return 0;

}