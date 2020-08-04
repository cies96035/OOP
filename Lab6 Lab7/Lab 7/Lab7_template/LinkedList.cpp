#include"LinkedList.h"

LinkedList::LinkedList()
{
	//Constructor
	Head = NULL;
}

void LinkedList::Push_back(int x)
{
	ListNode *back_element= new ListNode(x);
	ListNode *s=Head;
	if(s==NULL)
	{
		Head=back_element;
		return;
	}
	while(s->next!=NULL)//find the last node
		s=s->next;
	s->next=back_element;//add new element behind last node
	return;
}

void LinkedList::Push_front(int x)
{
	ListNode *first_element = new ListNode(x);
	//add new element in front of Head
	first_element->next=Head;
	Head=first_element;
}

void LinkedList::Insert(int index,int x)
{
	//special case,if index is zero
	if(index==0)
	{
		Push_front(x);
		return;
	}
	ListNode *search_index=Head;//find specific node
	ListNode *tmp=new ListNode(x);//insert this element
	for(int i=1;i<index;i++)//find the node in front of index's element
		search_index=search_index->next;
	//insert
	tmp->next=search_index->next;
	search_index->next=tmp;
	return;
}

void LinkedList::Delete(int index)
{
	ListNode *s=Head,*tmp;
	//special case
	if(index==0)
	{
		Head=Head->next;
		delete s;
		return;
	}
	for(int i=1;i<index;i++)//find the node in front of index's element
		s=s->next;
	tmp=s->next;//the element need to delete
	s->next=s->next->next;//update new next
	delete tmp;//delete
	return ;
}

void LinkedList::Reverse()
{
	//force
	//only reverse the value
	for(ListNode *i=Head;i!=NULL;i=i->next)
		for(ListNode *j=i->next;j!=NULL;j=j->next)
			swap(i->val,j->val);

}


void LinkedList::Print()
{
	//TODO : Print all the elements in the linked list in order.
	cout << "List:";
	ListNode *s=Head;
	while(s!=NULL)//output from first to end
	{
		cout<<' '<<s->val;
		s=s->next;
	}
	return;
}

LinkedList::~LinkedList()
{
	ListNode *s=Head;
	
	while(s!=NULL)
	{
		ListNode *tmp=s->next;
		delete s;
		s=tmp;
	}
	Head=NULL;//initial
	return;
}
