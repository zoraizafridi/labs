#include<iostream>
using namespace std;
class Node{
public:
Node* prev;
Node* next;
int data;
Node(int value)
{
	data=value;
	prev=nullptr;
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
		void insertfront(int value)
		{
			Node* n=new Node(value);
			if(front==nullptr)
			{
				front=rear=n;
			}
			else{
				n->next=front;
				front->prev=n;
				front=n;
				
			}
		}
		void insertrear(int value)
		{
			Node* n=new Node(value);
			if(rear==nullptr)
			{
				front=rear=n;
			}
			else{
				rear->next=n;
				n->prev=rear;
				rear=n;
			}
		}
		void deletefront()
		{
			Node* current=front;
			if(front == nullptr) {
            cout << "Deque is empty";
            return;
        }
			
			else
			{
			front=front->next;
			if(front!=nullptr)
			{
				front->prev=nullptr;
			}
			delete current;
		}
	    }
	    	void deleterear()
		{
			Node* current=rear;
			if(rear == nullptr) {
            cout << "Deque is empty";
            return;
        }
			
			else
			{
			rear=rear->prev;
			if(rear!=nullptr)
			{
				rear->next=nullptr;
			}
			delete current;
		}
	    }
	    void display()
	    {
	    	Node* current=front;
	    	while(current!=nullptr)
	    	{
	    		cout<<" "<<current->data;
	    		current=current->next;
			}
		}
		int peekfront()
		{
			if(isempty())
			{
				return 1;
			}
			else
			{
				return front->data;
			}
		}
		int peekrear()
		{
			if(isempty())
			{
				return 1;
			}
			else{
				return rear->data;
			}
		}
		bool isempty()
		{
			return front==nullptr;
		}
};
int main()
{
	Queue q;
	q.insertfront(10);
	q.insertfront(20);
	cout<<"After insertion in front"<<endl;
	q.display();
	q.insertrear(30);
	q.insertrear(40);
	cout<<endl<<"After insertion in rear"<<endl;
	q.display();
	q.deletefront();
	cout<<endl<<"After deletion in front"<<endl;
	q.display();
	q.deleterear();
	cout<<endl<<"After deletion in rear"<<endl;
	q.display();
	cout<<endl<<"Peek front:"<<q.peekfront()<<endl;
	cout<<endl<<"Peek rear:"<<q.peekrear()<<endl;
}