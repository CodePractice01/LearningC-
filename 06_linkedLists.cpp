#include <iostream>

using namespace std;

struct Node
{
		int data;
		
		Node *link;//a pointer to a node
};

//redefining what node pointer looks like
typedef Node* nodePtr;

void insert (nodePtr& head, int data);

int main ()
{
	//create new node pointer ,called head
	nodePtr head;
	head = new Node; // point to a brand new node
		//populare node with data
		head -> data =20;
		head -> link = NULL;
	
	insert(head,30);
	
	nodePtr temp;
	temp = head;
	
	while(temp->link != NULL)
	{
		cout << temp->data << endl;
		temp = temp->link;
	}
	
	
	return 0;
}

void insert (nodePtr& head, int data)
{
	nodePtr tempPtr ;
	tempPtr = new Node;
	tempPtr -> data =data;
	tempPtr -> link = head;
	head = tempPtr;
}
