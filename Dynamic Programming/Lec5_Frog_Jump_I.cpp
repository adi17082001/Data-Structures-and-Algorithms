#include<bits/stdc++.h>
using namespace std;

// recursive solution
int f(int ind, vector<int>&arr){
	if(ind == 0) return 0;
	int jumpOne = f(ind - 1, arr) + abs(arr[ind] - arr[ind - 1]);
	int jumpTwo = INT_MAX;
	if(ind > 1){
		jumpTwo = f(ind - 2, arr) + abs(arr[ind] - arr[ind - 2]);
	}

	return min(jumpOne, jumpTwo);
}

int minJumps(vector<int>&jumps){
	int n = jumps.size();
	return f(n-1, jumps);
}

// memoization
int f(int ind, vector<int>&arr, vector<int>&dp){
	if(ind == 0) return 0;

	if(dp[ind] != -1) return dp[ind];

	// left recursion - for one jump, right recursion - for two jumps
	int jumpOne = f(ind - 1, arr, dp) + abs(arr[ind] - arr[ind - 1]);
	int jumpTwo = INT_MAX;
	if(ind > 1){
		jumpTwo = f(ind - 2, arr, dp) + abs(arr[ind] - arr[ind - 2]);
	}

	dp[ind] = max(jumpOne, jumpTwo);
	return dp[ind];
}

int minJumps(vector<int>&jumps){
	int n = jumps.size();
	vector<int>dp(n, -1);
	return f(n-1, jumps, dp);
}


// tabulation

int minJumps(vector<int>&jumps){
	int n = jumps.size();
	vector<int>dp(n, -1);

	dp[0] = 0;
	for(int i = 1; i < n; i++){
		int left = dp[i - 1] + abs(jumps[i] - jumps[i - 1]);
		int right = INT_MAX;
		if(i > 1){
			right = dp[i - 2] + abs(jumps[i] - jumps[i - 2]);
		}
		dp[i] = min(left, right);
	}
	return dp[n-1];	
}


// Space optimization

int minJumps(vector<int>&jumps){
	int n = jumps.size();
	int prev2 = 0, prev = 0;
	for(int i = 1; i < n; i++){
		int left = prev + abs(jumps[i] - jumps[i - 1]);
		int right = INT_MAX;
		if(i > 1){
			right = prev2 + abs(jumps[i] - jumps[i - 2]);
		}
		int curri = min(left, right);
		prev2 = prev;
		prev = curri;
	}
	return prev;
	
}

int main(){
	vector<int>jumps = {30,10,60,10,60,50};
	cout << minJumps(jumps);
}
