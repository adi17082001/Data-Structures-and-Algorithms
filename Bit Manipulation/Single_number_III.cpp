#include<bits/stdc++.h>
using namespace std;

// brute
// vector<int> twoDistinctSingleNumbers(vector<int>&arr){
// 	vector<int>ans;
// 	unordered_map<int,int>mpp;

// 	for(int i = 0; i < arr.size(); i++){
// 		mpp[arr[i]]++;
// 	}

// 	for(auto it: mpp){
// 		if(it.second == 1){
// 			ans.push_back(it.first);
// 		}
// 	}
// 	return ans;
// }


// optimal
vector<long> twoDistinctSingleNumbers(vector<int>&arr){
	vector<long>ans;
	
	long xorr = 0;
	for(int i = 0; i < arr.size(); i++){
		xorr = xorr ^ arr[i];
	}

	long rightmost = (xorr & xorr-1) ^ xorr;
	long b1 = 0, b2 = 0;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] & rightmost){
			b1 = b1 ^ arr[i];
		}else{
			b2 = b2 ^ arr[i];
		}
	}

	ans.push_back(b1);
	ans.push_back(b2);

	return ans;
}

int main(){
	vector<int>arr = {2,4,2,14,3,7,7,3};

	vector<long>ans = twoDistinctSingleNumbers(arr);

	for(auto i: ans){
		cout << i << " ";
	}
}
