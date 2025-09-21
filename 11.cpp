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
class Stack{
	public:
		Node* top;
		Stack()
		{
			top=nullptr;
		}
		void Push(int value)
		{
		Node* n=new Node(value);
			n->next=top;
			top=n;
		}
		void Pop()
		{
			if(top==nullptr)
			{
				cout<<"Empty";
				return;
			}
			else{
				Node* temp=top;
				top=top->next;
				delete temp;
			}
		}
		void display()
		{
			Node* temp=top;
			while(temp!=nullptr)
			{
				cout<<" "<<temp->data;
				temp=temp->next;
			}
		}
};
int main()
{
	Stack s;
	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.display();
	cout<<endl;
	cout<<"After popping";
	s.Pop();
	s.display();
	return 0;
}