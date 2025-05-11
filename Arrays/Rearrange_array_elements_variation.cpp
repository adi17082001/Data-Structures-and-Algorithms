#include<bits/stdc++.h>
using namespace std;

vector<int>rearrangeArray(vector<int>&arr){
	int n = arr.size();
	vector<int>ans(n);
	int posIndex = 0, negIndex = 1;
	vector<int>pos;
	vector<int>neg;
	for(int i = 0; i < n; i++){
		if(arr[i] > 0) pos.push_back(arr[i]);
		if(arr[i] < 0) neg.push_back(arr[i]);
	}
	if(pos.size() > neg.size()){
		for(int i = 0; i < neg.size(); i++){
			ans[2*i] = pos[i];
			ans[2*i + 1] = neg[i];
		}
		int index = neg.size() * 2;
		for(int i = neg.size(); i < pos.size(); i++){
			ans[index] = pos[i];
			index++;
		}
	}
	else{
		for(int i = 0; i < pos.size(); i++){
			ans[2*i] = pos[i];
			ans[2*i + 1] = neg[i];
			int index = pos.size() * 2;
			for(int i = pos.size(); i < neg.size(); i++){
				ans[index] = neg[i];
				index++;
			}
		}
	}
	return ans;
}


int main(){
	vector<int>arr = {1,2,-4,-5,3,6};
	vector<int> ans = rearrangeArray(arr);
	for(auto i: ans){
		cout << i << " ";
	}
}
