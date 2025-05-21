#include<bits/stdc++.h>
using namespace std;


// // brute force -> gives time limit exceeded

// void findCombinations(int i, vector<int>&arr, int target, set<vector<int>>&ans, vector<int>&ds){
// 	if(i == arr.size()){
// 		if(target == 0){
// 			ans.insert(ds);
// 		}
// 		return;
// 	}

// 	if(arr[i] <= target){
// 		ds.push_back(arr[i]);
// 		findCombinations(i+1, arr, target - arr[i], ans, ds);
// 		ds.pop_back();
// 	}
// 	findCombinations(i+1, arr, target, ans, ds);
// 	return;
// }


// vector<vector<int>>combinationSum2(vector<int>&arr, int target){
// 	sort(arr.begin(), arr.end());
// 	set<vector<int>>ans;
// 	vector<int>ds;
// 	findCombinations(0, arr, target, ans, ds);
// 	vector<vector<int>>res(ans.begin(), ans.end());
// 	return res;
// }


void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}

int main(){
	vector<int>arr = {2,5,2,1,2};
	int target = 5;
	vector<vector<int>>ans = combinationSum2(arr, target);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
