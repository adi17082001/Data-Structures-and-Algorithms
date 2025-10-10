#include<bits/stdc++.h>
using namespace std;


// recursion
bool f(int ind, int target, vector<int>&arr){
	if(target == 0) return true;
	if(ind == 0) return (arr[0] == target);

	bool notTake = f(ind - 1, target, arr);
	bool take = false;
	if(target >= arr[ind]){
		take = f(ind - 1, target - arr[ind], arr);
	}

	return take || notTake;
}

// memoization
bool f(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
	if(target == 0) return true;
	if(ind == 0) return (arr[0] == target);
	// memoization step
	if(dp[ind][target] != -1) return dp[ind][target];

	bool notTake = f(ind - 1, target, arr, dp);
	bool take = false;
	if(target >= arr[ind]){
		take = f(ind - 1, target - arr[ind], arr, dp);
	}

	// return take || notTake;
	dp[ind][target] = (take || notTake);
	return dp[ind][target];
}

// tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];
}

// space optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a vector 'prev' to store the previous row of the DP table
    vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }

        // Update 'prev' with the current row 'cur' for the next iteration
        prev = cur;
    }

    // The final result is stored in prev[k]
    return prev[k];
}


int main(){
	vector<int>arr = {2,3,1,1};
	// int target = 4;
	// vector<vector<int>> dp(1001, vector<int>(1001, -1));

	// cout << f(arr.size() - 1, target, arr, dp);
	cout << subsetSumToK(4, 4, arr);
}
