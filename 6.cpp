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
class List{
	public:
		Node* head;
		List()
		{
		head=nullptr;	
		}
		void insertioninbegin(int value)
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
		List merge(List& l1,List& l2)
		{
			Node* p1=l1.head;
			Node* p2=l2.head;
			Node dummy(0);
			Node* tail=&dummy;
			while(p1!=nullptr && p2!=nullptr)
			{
				if(p1->data<p2->data)
				{
					tail->next=p1;
					p1=p1->next;
				}
				else{
					tail->next=p2;
					p2=p2->next;
				}
				tail=tail->next;
			}
			if(p1!=nullptr)
			{
				tail->next=p1;
			}
			if(p2!=nullptr)
			{
				tail->next=p2;
			}
			List result;
			result.head=dummy.next;
			return result;
		}
};

int main()
{
	List l1,l2;
	l1.insertioninbegin(4);
	l1.insertioninbegin(2);
	l1.insertioninbegin(1);
	cout<<"List 1"<<endl;
	l1.display();
	cout<<endl;
	l2.insertioninbegin(4);
	l2.insertioninbegin(3);
	l2.insertioninbegin(1);
	cout<<"List 2"<<endl;
	l2.display();
	cout<<endl;
	cout<<"Merge list"<<endl;
	List l=l1.merge(l1,l2);
	l.display();
	return 0;
}