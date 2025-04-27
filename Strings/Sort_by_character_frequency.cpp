#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s){
	// store freq in map
	unordered_map<char,int> mpp;
	for(char ch: s){
		mpp[ch]++;
	}

	// need to sort map in descending order
	// cant custom sort map directly, so convert to vector

	vector<pair<char,int>> freq(mpp.begin(), mpp.end());

	// custom sort - sort in desc order
	sort(freq.begin(), freq.end(), [](auto &a, auto &b){
		return a.second > b.second;
	});


	string res = "";
	for(auto &i: freq){
		res += string(i.second, i.first);
	}
	return res;
}

int main(){
  string s = "tree";
  cout << frequencySort(s);
}
