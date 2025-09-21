#include<iostream>
using namespace std;
class Node{
public:
Node* next;
Node* prev;
string data;
Node(string val)
{
next=nullptr;
prev=nullptr;
data=val;	
}	
};
class BrowserHistory{
public:
	Node* head;
	BrowserHistory(string homepage)
	{
		head=new Node(homepage);
	}
	void Visit(string url)
	{
		if(head->next!=nullptr)
		{
			Node* temp=head->next;
			while(temp!=nullptr)
			{
				Node* current=temp;
				temp=temp->next;
				delete current;
			}
			head->next=nullptr;
			
		}
	    Node* n = new Node(url);
		head->next=n;
		n->prev=head;
		head=n;
	}
	string Back(int steps)
	{
		while(head->prev && steps--)
		{
			head=head->prev;
		}
		return head->data;
	}
	string Front(int steps)
	{
		while(head->next && steps--)
		{
			head=head->next;
		}
		return head->data;
	}
	
};
int main()
{
	BrowserHistory J("leetcode.com");
	J.Visit("Mashood.com");
	J.Visit("SakinaGotogatar.com");
	J.Visit("CID MATCHAFICATION");;
	cout<<J.Back(1)<<endl;
	cout<<J.Back(1)<<endl;
	cout<<J.Front(1)<<endl;
	J.Visit("SAKINAFICATION.com");
	cout<<J.Front(1)<<endl;
	cout<<J.Back(3)<<endl;
	cout<<J.Back(7)<<endl;
	return 0;
}