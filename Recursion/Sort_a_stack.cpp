#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int temp){
	if(st.empty() || st.top() <= temp){
		st.push(temp);
		return;
	}
	int val = st.top();
	st.pop();
	insert(st, temp);
	st.push(val);
	return;
}

void sortStack(stack<int> &st){
	if(st.size() == 1) return;
	int temp = st.top();
	st.pop();
	sortStack(st);
	insert(st, temp);
	return;
}

int main(){
	stack<int> st;
	st.push(1);
	st.push(5);
	st.push(0);
	st.push(2);

	cout << "Before sorting:\n";
	stack<int> temp = st;
	while(!temp.empty()){
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << "\n";

	sortStack(st);

	cout << "After sorting:\n";
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}
