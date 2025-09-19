#include<bits/stdc++.h>
using namespace std;

int maxSumOfSubarrayWithSizeK(vector<int>&arr, int k){
	int n = arr.size();
	int maxSum = 0;
	int l = 0, r = k-1;
	int sum = 0;

	for(int i = l; i <= r; i++){
		sum += arr[i];
	}

	while(r < n-1){
		sum = sum - arr[l];
		l++;
		r++;
		sum = sum + arr[r];
		maxSum = max(maxSum, sum);
	}
	return maxSum;
}

int main(){
	vector<int> arr = {-1,2,3,3,4,5,-1};
	int k = 4;
	cout << maxSumOfSubarrayWithSizeK(arr, k);
}
