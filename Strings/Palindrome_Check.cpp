#include<bits/stdc++.h>
using namespace std;


// brute
// use reverse() stl method. 

// optimal
bool isPalindrome(string &str){
	int low = 0;
	int high = str.size() - 1;
	while(low < high){
		if(str[low] != str[high]){
			return false;
		}
		low++;
		high--;
	}
	return true;
}


int main(){
	string s = "abcba";
	cout << isPalindrome(s);
}
