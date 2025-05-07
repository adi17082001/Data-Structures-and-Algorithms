#include<bits/stdc++.h>
using namespace std;

void findCombinations(int i, vector<int>&arr, int target, vector<vector<int>>&ans, vector<int>&ds){
	if(i == arr.size()){
		if(target == 0){
			ans.push_back(ds);
		}
		return;
	}

	if(arr[i] <= target){
		ds.push_back(arr[i]);
		findCombinations(i, arr, target - arr[i], ans, ds);
		ds.pop_back();
	}
	findCombinations(i+1, arr, target, ans, ds);
	return;
}


vector<vector<int>>combinationSum(vector<int>&arr, int target){
	vector<vector<int>>ans;
	vector<int>ds;
	findCombinations(0, arr, target, ans, ds);
	return ans;
}

int main(){
	vector<int>arr = {2,3,6,7};
	int target = 7;
	vector<vector<int>>ans = combinationSum(arr, 7);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
