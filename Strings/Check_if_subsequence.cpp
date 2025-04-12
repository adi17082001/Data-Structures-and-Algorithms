#include<bits/stdc++.h>
using namespace std;

// check if s2 is a substring of s1
bool isSubsequence(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	int i = 0, j = 0;

	if(n < m) return false;
	while(i < n && j < m){
		if(s1[i] == s2[j]){
			i++;
			j++;
		}
		else{
			i++;
		}
	}
	return (j == m);
}

int main(){
	string s1 = "abcd";
	string s2 = "acd";

	cout << isSubsequence(s1, s2);
}
