#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&s, int ele){
	if(s.size() == 0){
		s.push(ele);
		return;
	}
	int temp = s.top();
	s.pop();
	insert(s, ele);
	s.push(temp);
	return;
}

void reverseStack(stack<int>&s){
	if(s.size() == 1) return;
	int temp = s.top();
	s.pop();
	reverseStack(s);
	insert(s, temp);
	return;
}


int main(){
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	reverseStack(s);

	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}
