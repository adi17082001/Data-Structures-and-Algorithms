#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i];
	}
	cout << endl;
}

void generateAllBinaryStrings(int n, int arr[], int i){
	if(i == n){
		printArray(arr, n);
		return;
	}
	arr[i] = 0;
	generateAllBinaryStrings(n, arr, i+1);

	arr[i] = 1;
	generateAllBinaryStrings(n, arr, i+1);
}


vector<string> func(int n, int arr[], int i, vector<string>&res){
	if(i == n){
		string ans = "";
		for(int j = 0; j < n; j++){
			ans += to_string(arr[j]);
		}
		res.push_back(ans);
		return res;
	}
	arr[i] = 0;
	func(n, arr, i+1, res);

	arr[i] = 1;
	func(n, arr, i+1, res);

	return res;
}

vector<string>help(int n){
	int arr[n];
	vector<string> result(0);
	vector<string>ans = func(n, arr, 0, result);
	return ans;
}

int main(){
	vector<string>res = help(4);
	for(auto i: res){
		cout << i << endl;
	}
}
