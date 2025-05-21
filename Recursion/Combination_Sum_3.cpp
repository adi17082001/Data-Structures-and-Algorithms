#include<bits/stdc++.h>
using namespace std;

void func(int i, int k, int sumTillNow, int n, vector<int>&subset, vector<vector<int>>&ans){
	if(k < 0) return;
	if(sumTillNow == n){
		if(k == 0){
			ans.push_back(subset);
		}
		return;
	}
	if(i == 10) return;  // as only nos 1 to 9 are allowed

	// pick
	sumTillNow = sumTillNow + i;
	subset.push_back(i);
	func(i+1, k-1, sumTillNow, n, subset, ans);

	sumTillNow = sumTillNow - i;
	subset.pop_back();

	// ignore
	func(i+1, k, sumTillNow, n, subset, ans);
}

vector<vector<int>> combinationSum3(int k, int n){
	vector<vector<int>>ans;
	vector<int>subset;
	func(1, k, 0, n, subset, ans);
	return ans;
}


int main(){
	int k = 3, n = 9;
	vector<vector<int>>ans = combinationSum3(k, n);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
