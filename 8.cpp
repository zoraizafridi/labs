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
		Node* mergesort(Node* head)
		{
			if(head==nullptr || head->next==nullptr)
			{
				return head;
			}
			Node* slow=head;
			Node* fast=head;
			Node* prev=nullptr;
			while(fast!=nullptr && fast->next!=nullptr)
			{
				prev=slow;
				fast=fast->next->next;
				slow=slow->next;
			}
			prev->next=nullptr;
			Node* left=mergesort(head);
			Node* right=mergesort(slow);
			return merge(left,right);
		}
		Node* merge(Node* l1,Node* l2)
		{
			Node dummy(0);
			Node* tail=&dummy;
			while(l1!=nullptr && l2!=nullptr)
			{
				if(l1->data<l2->data)
				{
					tail->next=l1;
					l1=l1->next;
				}
				else{
					tail->next=l2;
					l2=l2->next;
				}
				tail=tail->next;
			}
			if(l1!=nullptr)
			{
				tail->next=l1;
			}
			if(l2!=nullptr)
			{
				tail->next=l2;
			}
			return dummy.next;
		}
		void sort()
		{
			head=mergesort(head);
			
		}
};
int main()
{
	List l;
	l.insert(3);
	l.insert(1);
	l.insert(2);
	l.insert(4);
	l.display();
	cout<<endl;
	cout<<"After sorting"<<endl;
	l.sort();
	l.display();
	return 0;
	
}