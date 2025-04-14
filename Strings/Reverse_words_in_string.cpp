#include<bits/stdc++.h>
using namespace std;

// brute 

string reversedWords(string &s) {
	int n = s.length();
    stack<string> st;
    string ans = "";
    for(int i = 0; i < n; i++){
    	string word = "";
    	while(i < n && s[i] != ' '){
    		word += s[i];
    		i++;
    	}
    	if(word.length() > 0) st.push(word);
    }
    while(!st.empty()){
    	ans += " " + st.top();
    	st.pop();
    }
    return ans.substr(1);
}


// optimal

string reversedWords(string &s){
	int n = s.length();
	string ans = "";
	reverse(s.begin(), s.end());

	for(int i = 0; i < n; i++){
		string word = "";
		while(i < n && s[i] != ' '){
			word += s[i];
			i++;
		}
		reverse(word.begin(), word.end());
		if(word.length() > 0){
			ans += " " + word;
		}
	}
	return ans.substr(1); // remove the whitespace at position 0. 
}

int main(){
	string s = "the    world is a    dark place   ";
	cout << reversedWords(s);
}
