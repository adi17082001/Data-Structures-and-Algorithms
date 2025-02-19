#include<bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>>&matrix, int n, int m, int col){
	int maxValue = -1;
	int index = -1;
	for(int i = 0; i < n; i++){
		if(matrix[i][col] > maxValue){
			maxValue = matrix[i][col];
			index = i;
		}
	}
	return index;
}


vector<int>findPeakElement(vector<vector<int>>&matrix){
	int n = matrix.size();
	int m = matrix[0].size();
	
	int low = 0, high = m-1;
	while(low <= high){
		int mid = (low + high)/2;
		int row = findMaxIndex(matrix, n, m, mid);
		int left = (mid - 1 > 0 ? matrix[row][mid-1] : -1);
		int right = (mid + 1 < m ? matrix[row][mid+1] : -1);

		if(matrix[row][mid] > left && matrix[row][mid] > right){
			return {row, mid};
		}
		else if(matrix[row][mid] < left){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	return {-1,-1};
}


int main(){
	vector<vector<int>>matrix = {{4,2,5,1,4,5},
								 {6,9,3,2,3,2},
								 {1,7,6,0,1,3},
								 {3,6,2,3,7,2}};

	// cout << matrix[4][0];
	vector<int>ans = findPeakElement(matrix);
	for(auto i: ans){
		cout << i << " ";
	}
}
