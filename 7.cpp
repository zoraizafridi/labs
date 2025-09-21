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
		void insertion(int value)
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
		void deleteduplicate()
		{
			Node* current=head;
			Node* dupli=head;
			while(current!=nullptr)
			{
				dupli=current;
				while(dupli->next!=nullptr)
				{
					if(dupli->next->data==current->data)
					{
						Node* temp=dupli->next;
						dupli->next=dupli->next->next;
						delete temp;
					}
					else{
					dupli=dupli->next;}
				}
				current=current->next;
			}
		}
};
int main()
{
	List l;
	l.insertion(3);
	l.insertion(3);
	l.insertion(2);
	l.insertion(1);
	l.insertion(1);
	l.display();
	cout<<endl;
	cout<<"After deletion"<<endl;
	l.deleteduplicate();
	l.display();
	return 0;
	return 0;
}