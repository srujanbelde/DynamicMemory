#include "AppliancePtr.h"

class Node
{
private:
	AppliancePtr appliancePtr;
	Node* next;
public:
	Node();
	AppliancePtr& getData();
	Node* getNext();
	void setNext(Node*);
};

class Iterator
{
private:
	Node* node;
public:
	Iterator(Node*);
	void operator++();
	void operator++(int);
	void operator=(Iterator);
	bool operator!=(Iterator&);
	Node* operator->() const;
	operator Node*();
};

class List
{   
    private:
        Node* head;
		Node* tail;
		Iterator currentNode;

		void recursiveDelete(Node*);
    public:
        List();
        List(int);
        ~List();
		void setCurrentNode(Iterator);
		Iterator begin();
		Iterator end();
		Iterator& getCurrentNode();
};

