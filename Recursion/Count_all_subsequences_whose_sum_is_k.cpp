#include<bits/stdc++.h>
using namespace std;


int printSubsequencesWhoseSumIsK(int i, vector<int>&nums, int sum, vector<int>&ds, int k){
	if(i == nums.size()){
		// condition satisfied
		if(sum == k) return 1;

		// condition not satisfied
		else return 0;
	}
	ds.push_back(nums[i]);
	sum += nums[i];
	int l = printSubsequencesWhoseSumIsK(i+1, nums, sum, ds, k);

	ds.pop_back();
	sum -= nums[i];
	int r = printSubsequencesWhoseSumIsK(i+1, nums, sum, ds, k);

	return l + r;
}

int main(){
	vector<int>nums = {1,2,1,1,1,3};
	vector<int>ds;
	cout << printSubsequencesWhoseSumIsK(0, nums, 0, ds, 4);
}
