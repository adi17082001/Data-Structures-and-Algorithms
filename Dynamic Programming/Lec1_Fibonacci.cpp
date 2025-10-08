#include<bits/stdc++.h>
using namespace std;


// recursive
int fibo(int n, vector<int>&dp){
	if(n <= 1) return n;

	if(dp[n] != -1) return dp[n];

	dp[n] = fibo(n-1, dp) + fibo(n-2, dp);

	return dp[n];
}


// tabulation
int fibo_tabulation(int n){
	vector<int>dp(n+1, -1);
	dp[0] = 0, dp[1] = 1;

	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}


// optimize O(N) -> O(1) space
int fibo_SCOptimized(int n){
	int prev2 = 0, prev = 1;
	for(int i = 2; i <= n; i++){
		int curri = prev + prev2;
		prev2 = prev;
		prev = curri;
	}
	return prev;
}

int main(){
	// int n = 5;
	// vector<int>dp(n+1, -1);

	// cout << fibo(n, dp);

	// cout << fibo_SCOptimized(5);
	cout << fibo_tabulation(5);
}
