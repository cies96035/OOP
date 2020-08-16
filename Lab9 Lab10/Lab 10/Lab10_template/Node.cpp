#include "Node.h"
int Node::getValue() 
{
    return this->value;
}

Node* Node::getLchild() 
{
    return this->lchild;
}

Node* Node::getRchild() 
{
    return this->rchild;
}

void Node::setLchild(Node* node) 
{
    lchild=node;
}

void Node::setRchild(Node* node) 
{
    rchild=node;
}