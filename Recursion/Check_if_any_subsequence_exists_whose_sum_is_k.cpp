#include<bits/stdc++.h>
using namespace std;

bool printSubsequencesWhoseSumIsK(int i, vector<int>&nums, int sum, vector<int>&ds, int k){
	if(i == nums.size()){
		if(sum == k){
			return true;
		}
		else return false;
	}

	ds.push_back(nums[i]);
	sum += nums[i];
	if(printSubsequencesWhoseSumIsK(i+1, nums, sum, ds, k)) return true;

	ds.pop_back();
	sum -= nums[i];
	if(printSubsequencesWhoseSumIsK(i+1, nums, sum, ds, k)) return true;

	return false;
}

int main(){
	vector<int>nums = {1,2,1,1,1,3};
	vector<int>ds;
	cout << printSubsequencesWhoseSumIsK(0, nums, 0, ds, 10);
}
