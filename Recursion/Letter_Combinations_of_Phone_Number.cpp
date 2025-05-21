#include<bits/stdc++.h>
using namespace std;

void func(int i, string &s, string &temp, vector<string>&ans, unordered_map<char, string> &mpp){
	// base case
	if(i == s.size()){
		ans.push_back(temp);
		return;
	}

	string str = mpp[s[i]];
	for(int j = 0; j < str.size(); j++){
		temp.push_back(str[j]);
		func(i+1, s, temp, ans, mpp);
		temp.pop_back();
	}
}

vector<string>combinations(string s){

	vector<string>ans;
	if(s == "") return ans;

	unordered_map<char, string> mpp;
	mpp['2'] = "abc";
	mpp['3'] = "def";
	mpp['4'] = "ghi";
	mpp['5'] = "jkl";
	mpp['6'] = "mno";
	mpp['7'] = "pqrs";
	mpp['8'] = "tuv";
	mpp['9'] = "wxyz";

	string temp;
	func(0, s, temp, ans, mpp);
	return ans;
}

int main(){
	string s = "37";
	vector<string>ans = combinations(s);
	for(auto i: ans){
		cout << i << endl;
	}
}
