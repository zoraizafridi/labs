#include<iostream>
using namespace std;
class Node{
	public:
Node* next;
int data;
Node(int value)
{
	next=nullptr;
	data=value;
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
		rear->next=front; //if it is empty
	}
	else{
		rear->next=n;
		rear=n;
		rear->next=front;
	}
}
void Dequeue()
{
	if(front==rear)
	{
		delete front;
		front=rear=nullptr;//if it is empty
	}
	else{
		Node* current=front;
		front=front->next;
		rear->next=front;
		delete current;
	}
	}
	void display()
	{
		Node* temp=front;
		do{
			cout<<" "<<temp->data;
			temp=temp->next;
		}
		while(temp!=front);
	}
};
int main()
{
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.display();
	cout<<endl;
	cout<<"Dequeing"<<endl;
	q.Dequeue();
	q.Dequeue();
	q.display();
	return 0;
}