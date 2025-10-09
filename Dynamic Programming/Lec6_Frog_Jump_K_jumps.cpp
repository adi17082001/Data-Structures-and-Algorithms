#include<bits/stdc++.h>
using namespace std;

// recursion
int f(int ind, vector<int>& arr, int k) {
    if (ind == 0) return 0; // base case

    int minJumps = INT_MAX;

    // try all jumps from 1 to k
    for (int i = 1; i <= k; i++) {
        if (ind - i >= 0) { // check valid index
            int jump = f(ind - i, arr, k) + abs(arr[ind] - arr[ind - i]);
            minJumps = min(minJumps, jump);
        }
    }

    return minJumps;
}

int minJumps(vector<int>&jumps){
	int n = jumps.size();
	return f(n-1, jumps, 3);
}

// tabulation
int f(vector<int>&arr, vector<int>&dp, int k){
	int n = arr.size();
	dp[0] = 0;
	for(int i = 1; i < n; i++){
		int minJumps = INT_MAX;
		for(int j = 1; j <= k; j++){
			if(i - j >= 0){
				int jump = dp[i-j] + abs(arr[i] - arr[i - j]);
				minJumps = min(minJumps, jump);
			}
		}
		dp[i] = minJumps;
	}
	return dp[n-1];
}

int minJumps(vector<int>&jumps){
	int n = jumps.size();
	vector<int>dp(n,-1);
	return f(jumps, dp, 3);
}


int main(){
	vector<int>jumps = {30,10,60,10,60,10};
	cout << minJumps(jumps);
}
