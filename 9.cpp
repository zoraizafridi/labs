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
		bool palindrome()
		{
			Node* slow=head;
			Node* fast=head;
			while(fast!=nullptr && fast->next!=nullptr)
			{
				slow=slow->next;
				fast=fast->next->next;
			}//till middle
			Node* current=slow;
			Node* prev=nullptr;
			Node* next;
			while(current!=nullptr)
			{
				next=current->next;
				current->next=prev;
				prev=current;
			    current=next;
			}//reversal from the second half
			Node* first=head;
			Node* second=prev;
			while(second!=nullptr)
			{
				if(first->data!=second->data)
				{
					return false;
				}
				first=first->next;
				second=second->next;
			}
			return true;
		}
};
int main()
{
	List l;
	l.insert(1);
	l.insert(2);
	l.insert(2);
	l.insert(1);
	l.display();
	cout<<endl;
	cout<<"If it is palindrome[1(yes)/0(no)]:"<<l.palindrome();
	return 0;
}