#include<iostream>
using namespace std;
class Node{
	public:
Node* next;
int data;
Node(int value)
{
data=value;
next=nullptr;	
}	
};
class Queue{
	public:
	Node* front;
	Node* rear;
	Queue()
	{
		front=nullptr;
		rear=nullptr;
	}
	void Enqueue(int value)
	{
		Node* n=new Node(value);
		if(front==nullptr)
		{
			front=rear=n;
			rear->next=front;
		}
		else{
			rear->next=n;
			rear=n;
			rear->next=front;
		}
	}
	void Dequeue()
	{
		Node* current=front;
		if(front==nullptr)
		{
			return;
		}
		else{
			Node* current=front;
			front=front->next;
			rear->next=front;
			delete current;
		}
	}
	int peek()
	{
		if(isempty())
		{
			cout<<"Queue is empty";
			return -1;
		}
		return front->data;
	}
	bool isempty()
	{
		return front==nullptr;
	}
	void display()
	{
		Node* current=front;
		do{
			cout<<" "<<current->data;
			current=current->next;
		}
		while(current!=front);
	}
};
int main()
{
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	cout<<"Enqueue"<<endl;
	q.display();
	q.Dequeue();
	cout<<endl;
	cout<<"Dequeue"<<endl;
	q.display();
	cout<<endl;
	cout<<"Peek="<<q.peek();
	cout<<endl;
	cout<<"If it is empty[1] if not[0]:"<<q.isempty();
	return 0;
}