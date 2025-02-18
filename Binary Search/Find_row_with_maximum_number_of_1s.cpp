#include<bits/stdc++.h>
using namespace std;


// ------------------------- brute ---------------------- //

int rowWithMaxNumberOfOnes_brute(vector<vector<int>>&arr, int n, int m){
	int ind = -1;
	int max_cnt = 0;
	for(int i = 0; i < n; i++){
		int cnt_row = 0;
		for(int j = 0; j < m; j++){
			cnt_row += arr[i][j];
		}
		if(cnt_row > max_cnt){
			max_cnt = cnt_row;
			ind = i;
		}
	}
	return ind;
}


// ------------------------- optimal --------------------------- //

int lowerBound(vector<int> arr, int x) {
	// Write your code here
	int n = arr.size();
	int low = 0, high = n-1;
	int ans = n;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]>=x){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}

int rowWithMaxNumberOfOnes_Optimal(vector<vector<int>>matrix, int n, int m){
	int max_cnt = 0;
	int ind = -1;
	for(int i = 0; i < n; i++){
		int cnt_ones = m - lowerBound(matrix[i], 1);
		if(cnt_ones > max_cnt){
			max_cnt = cnt_ones;
			ind = i;
		}
	}
	return ind;
}




int main(){
	vector<vector<int>>arr = {{0,0,1,1,1},
							  {0,0,0,0,0},
							  {0,1,1,1,1},
							  {0,0,0,0,0},
							  {0,1,1,1,1}};

	// cout << rowWithMaxNumberOfOnes_brute(arr, 5, 5);

	cout << rowWithMaxNumberOfOnes_Optimal(arr, 5, 5);
}
