#include<iostream>
using namespace std;

template<class T>
class Node
{
public :
  Node();
	Node(T);
	~Node();
	void addData(T value);
	void print();
	void revPrint();
	Node *next;
private:
	struct Cell
	{
		T data;
		Cell *link;
		Cell *blink;
	};
	Cell *start;
	Cell *cursor;
};

template<class T>
Node<T>:: Node()
{
	start = cursor = new Cell;
	start -> link  = NULL;
	start -> blink = NULL;
	next = NULL;
	cout << "Constructor OK." << endl;
}


template<class T>
Node<T>::Node(T value)
{
	start = cursor = new Cell;
	Cell *n = new Cell;
	n->data = value;
	start  = n;
	cursor = n;
	next = NULL;
	n->blink = NULL;
	cout << "Create Node Success." << endl;
}

template<class T>
Node<T>::~Node()
{
		Cell *cp = start;
		while(cp != cursor)
		{
			Cell *next = cp->link;
			cout << "Delete " << cp->data << endl;
			delete cp;
			cp = next;
		}
		cout << "Delete " << cp->data << endl;
		delete cp;
}
			

template<class T>
void Node<T>:: addData(T value)
{
	Cell *n = new Cell;
	n->data  = value; 
	cursor->link = n;
	Cell *temp = cursor;
	cursor = n;
	n->blink = temp;
	n->link = NULL;
}

template<class T>
void Node<T>:: revPrint()
{
	if(cursor != start)
	{
	cout << cursor->data << endl; 
	cursor = cursor->blink;
	revPrint();
	}
	if(cursor->link != NULL)
	cursor = cursor->link;
}

template<class T>
void Node<T>:: print()
{
	if(cursor->blink != start)
	{
		cursor = cursor->blink; 
		print();
	}
	cout << cursor->data << endl; 
	if(cursor->link != NULL)	
		cursor = cursor->link;
}

template<class T>
void createListWithNodeNo(Node<T> *n1, Node<T> *n2, int a, int b )
{
	if(a!=b){createListWithNodeNo(n1,n2,a+1,b);}
	n2 = new Node <int>(1);
	n1 = new Node<int>(a);
	n2->next = n1;
	n2 = n1;
}


int main()
{
	Node<int> linkedlist;
	linkedlist.addData(4);
	linkedlist.addData(5);
	linkedlist.addData(6);
	linkedlist.addData(7);
	linkedlist.addData(8);
	linkedlist.addData(9);
	
	Node<int> *h, *p, *t;
	/*
	h = t = new Node<int>(1);
	for(int i=2; i<=4; i++)
	{
		p = new Node<int>(i);
		t->next = p;
		t = p;
	}
	*/
		
	h = t = NULL;
	createListWithNodeNo(h, t, 1, 5);
	cout << "print: " << endl;
	linkedlist.print();
	cout << "revPrint " << endl;
	linkedlist.revPrint();
	return 0;
}
