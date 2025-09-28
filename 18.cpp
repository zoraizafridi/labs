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
//				cout<<"pop sucessful : "<< temp->a <<endl;
				return(temp->a);
			}
		}
		char peek(){
			return top->a;
		}
		
};


bool compareStr(string s,string t){
	stack* sst = new stack();
	stack* tst = new stack();
	
	for(int i=0;i<s.length();i++){
		if(s[i]	!= '#'){
		sst->push(s[i]);
		}else{
			sst->pop();
		}
	}
	
	for(int i=0;i<t.length();i++){
		if(t[i]	!= '#'){
		tst->push(t[i]);
		}else{
			tst->pop();
		}
	}
	
	
	while(sst->top != nullptr && tst->top != nullptr){
		if(sst->peek()== tst->peek()){
			sst->pop();
			tst->pop();
		}
		else{
			return false;
		}
	}
	return true;
}



int main(){
	
	cout<<"Comapring str result : "<<compareStr("ab#ccz", "ad#ccz")<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}