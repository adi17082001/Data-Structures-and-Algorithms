#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementI_brute(vector<int>&arr){
	int n = arr.size();
	vector<int>nge(n, -1);   // initialize with -1, i.e. if nge not found, we assign -1

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(arr[j] > arr[i]){
				nge[i] = arr[j];
				break;
			}
		}
	}
	return nge;
}

vector<int> nextGreaterElementI_optimal(vector<int>&arr){
	int n = arr.size();
	vector<int>nge(n);

	stack<int>st;

	for(int i = n-1; i >= 0; i--){
		while(!st.empty() && st.top() <= arr[i]){
			st.pop();
		}
		if(st.empty()){
			nge[i] = -1;
		}
		else{
			nge[i] = st.top();
		}
		st.push(arr[i]);
	}

	return nge;
}


int main(){
	// vector<int>arr = {6,0,8,1,3};
	vector<int>arr = {4,12,5,3,1,2,5,3,1,2,4,6};

	vector<int> nge = nextGreaterElementI_optimal(arr);

	for(int i : nge){
		cout << i << " ";
	}
}
