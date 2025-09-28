#include<iostream>

using namespace std;

class node{
	public:
		char a;
		node* prev;
		
		node(char x): a(x), prev(nullptr){};
};

class stack{
	public:
		node* top=nullptr;
		stack(): top(nullptr){
		}
		void push(char s){
			
				node* newnode = new node(s);
				newnode->prev = top;
				top = newnode;
//				cout<<"push sucessful : "<< s<<endl;

		}
		char pop(){
			if(top == nullptr){
				return 0;
			}else{
				node* temp = top;
				top = top->prev;
				return(temp->a);
			}
		}
		char peek(){
			return top->a;
		}
		
};

bool checkPalindrome(string s){
		stack* stack1 = new stack();
		
		if ((s.length())%2==0){
			for(int i =0; i<(s.length())/2;i++){
				stack1->push(s[i]);}
		}
		else{
			
			for(int i =0; i<(s.length()/2)+1;i++){
				stack1->push(s[i]);
			}
			stack1->pop();
		}
			
		while(stack1->top->prev != nullptr){
			int i=1;
			if(stack1->top->a == s[i]){
				stack1->pop();
				i++;
			}else{
				return false;
			}
		}	return true;
		
		
			
			
		
			
}

int main(){
	
	cout<<"check Palindrome result: "<<checkPalindrome("noon")<<endl;	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}