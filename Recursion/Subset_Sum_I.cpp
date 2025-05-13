#include<bits/stdc++.h>
using namespace std;

// // brute force

// void solve(vector<int>nums,vector<int> op, vector<vector<int>> &m){ // m ko by address paas kiye as jo bhi changes m me ho wo vector wale fn me reflect ho and nums aur op ko pass by value kiye uska changes vector fn me reflect nahi hoga 
//     if(nums.size()==0){
//         m.push_back(op);
//         return;
//     }
//     vector<int>op1=op;
//     vector<int>op2=op;
//     op2.push_back(nums[0]);
//     nums.erase(nums.begin()+0);
//     solve(nums,op1, m);
//     solve(nums,op2, m);
// }

// // brute
// vector<int>subsetSum(vector<int>&arr){
// 	vector<int>subSum;
// 	vector<vector<int>> subsets;
//     vector<int>op;
//     solve(arr,op,subsets);

//     for(int i = 0; i < subsets.size(); i++){
//     	int sum = 0;
//     	for(int j = 0; j < subsets[i].size(); j++){
//     		sum += subsets[i][j];
//     	}
//     	subSum.push_back(sum);
//     }
//     sort(subSum.begin(), subSum.end());
//     return subSum;
// }

// optimal

void solve(int ind, int sum, vector<int>&arr, vector<int>&sumSubset){
	if(ind == arr.size()){
		sumSubset.push_back(sum);
		return;
	}
	//pick
	solve(ind+1, sum + arr[ind], arr, sumSubset);

	//not pick
	solve(ind+1, sum, arr, sumSubset);
}

vector<int>subsetSum(vector<int>&arr){
	vector<int>sumSubset;
	solve(0, 0, arr, sumSubset);
	sort(sumSubset.begin(), sumSubset.end());
	return sumSubset;
}



int main(){
	vector<int>arr = {3,1,2};
	vector<int>subSum = subsetSum(arr);
	for(auto i: subSum){
		cout << i << " ";
	}
}
