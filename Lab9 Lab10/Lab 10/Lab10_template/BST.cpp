#include "BST.h"
#include <vector>
void BST::insert(Node* insertNode) 
{
    //if insert node is the first element of BST
    if(root==NULL)
    {
        root=insertNode;
        return;
    }

    //tra to travel and traparent is tra's parent
	Node *tra=getRoot(),*traparent=NULL;

    //until there is a empty Node
    while(tra!=NULL)
    {
        //the left child is smaller
        if(insertNode->getValue() < tra->getValue())
        {
            traparent=tra;
            tra=tra->getLchild();
        }
        //the right child is bigger
        else
        {
            traparent=tra;
            tra=tra->getRchild();
        }
    }

    //update child imformation
    if(insertNode->getValue() < traparent->getValue())
        traparent->setLchild(insertNode);
    else
        traparent->setRchild(insertNode);
    return;
}
int BST::search(int value, int mode) 
{
    //tra : use for travel
    Node *tra=getRoot();
    if(mode==1)
    {
        //pos : to record the current position
        int pos=1;

        //until find the value or no possible element for value
        while(tra->getValue()!=value&&tra!=NULL)
        {
            if(value<tra->getValue())
            {
                tra=tra->getLchild();
                pos<<=1;
            }
            else
            {
                tra=tra->getRchild();
                pos=(pos<<1)+1;
            }
        }

        //if find the position of value
        if(tra)
            return pos;
        
        //if not
        return -1;
    }
    else
    {
        //use by LIFO
        std::vector<bool> srch;

        //binary tree
        //false to left (*2)
        //true to right (*2+1)
        while(value!=1)
        {
            if(value%2)
                srch.push_back(1);
            else
                srch.push_back(0);
            value/=2;
        }

        //travel
        while(!srch.empty())
        {
            if(!srch.back())
                tra=tra->getLchild();
            else
                tra=tra->getRchild();
            srch.pop_back();
        }
        return tra->getValue();
    }
}

//return its root
Node* BST::getRoot() 
{
    return root;
}