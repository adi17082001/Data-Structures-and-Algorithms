#include<bits/stdc++.h>
using namespace std;

// brute
string removeOuterParentheses_brute(string &s){
	string ans = "";
	stack<char>st;

	for(char c: s){
		if(c == '('){
			if(!st.empty()){
				ans += c;
			}
			st.push(c);
		}
		else{
			st.pop();
			if(!st.empty()){
				ans += c;
			}
		}
	}
	return ans;
}

// optimal

string removeOuterParentheses(string &s){
	string ans = "";
	int ct = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ')') ct--;
		if(ct != 0) ans += s[i];
		if(s[i] == '(') ct++;
	}
	return ans;
}


int main(){
	string s = "((()))(()())";

	// cout << removeOuterParentheses_brute(s);
	cout << removeOuterParentheses(s);
}