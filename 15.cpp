#include<iostream>
using namespace std;
class Node{
public:
Node* next;
Node* prev;
int data;
Node(int value)
{
data=value;
next=nullptr;
prev=nullptr;	
}	
};
class List{
public:
	Node* head;
	List()
	{
		head=nullptr;
	}
	void insert(int value)
	{
		Node* n=new Node(value);
		n->next=head;
		if(head!=nullptr)
		{
			head->prev=n;
		}
		head=n;
	}
	void display()
	{
		Node* current=head;
		while(current!=nullptr)
		{
			cout<<" "<<current->data;
			current=current->next;
		}
	}
	void concatenate(Node*& head1,Node*& head2)
	{
		if(head1==nullptr)
		{
			return;
		}
		else{
			Node* current=head1;
			while(current->next!=nullptr)
			{
				current=current->next;
			}
			current->next=head2;
			if(head2!=nullptr)
			{
				head2->prev=current;
			}
		}
	}
	void sort()
	{
		if(head==nullptr)
		{
			return;
		}
		Node* current=head;

		while(current!=nullptr)
		{
			Node* dupli=current->next;
			while(dupli!=nullptr)
			{
				if(dupli->data>current->data)
				{int temp=current->data;
				current->data=dupli->data;
				dupli->data=temp;
				}
				dupli=dupli->next;
			}
			current=current->next;
		}
	}
};
int main()
{
	List L,M;
	L.insert(10);
	L.insert(8);
	L.insert(6);
	L.insert(4);
	L.insert(2);
	cout<<"List 1"<<endl;
	L.display();
	cout<<endl;
	M.insert(9);
	M.insert(7);
	M.insert(5);
	M.insert(3);
	M.insert(1);
	cout<<"List 2"<<endl;
	M.display();
	cout<<endl;
	cout<<"Concatenation"<<endl;
	L.concatenate(L.head,M.head);
	L.display();
	cout<<endl;
	cout<<"After sorting";
	L.sort();
	L.display();
	return 0;
}