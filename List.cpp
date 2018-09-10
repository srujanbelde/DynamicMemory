#include "List.h"

Node::Node()
: appliancePtr(), next(NULL)
{
}

AppliancePtr& Node::getData()
{
    return appliancePtr;
}

void Node::setNext(Node* node)
{
    this->next = node;
}

Node* Node::getNext()
{
    return next;
}

List::List()
: head(), currentNode(head)
{
	tail = head->getNext();
}

List::List(int size)
: head(new Node), currentNode(head)
{
    Node* cur = head;
    for(int i = 0; i < size - 1; i++)
    {
        cur->setNext(new Node);
        cur = cur->getNext();
    }
	tail = cur->getNext();
}

void List::recursiveDelete(Node* node)
{
	if (!node)
	{
		return;
	}

	this->recursiveDelete(node->getNext());
	delete node;
}

List::~List()
{
	recursiveDelete(this->head);
}

void List::setCurrentNode(Iterator iter)
{
	this->currentNode = iter;
}

Iterator List::begin()
{
	return Iterator(head);
}

Iterator List::end()
{
	return Iterator(tail);
}

Iterator& List::getCurrentNode()
{
	return currentNode;
}

Iterator::Iterator(Node* iterNode)
: node(iterNode)
{
}

void Iterator::operator++()
{
	node = node->getNext();
}

void Iterator::operator++(int)
{
	node = node->getNext();
}

void Iterator::operator=(Iterator iter)
{
	this->node = iter.node;
}

bool Iterator::operator!=(Iterator& iter)
{
	return this->node != iter.node;
}

Node* Iterator::operator->() const
{
	return node;
}

Iterator::operator Node*()
{
	return node;
}


