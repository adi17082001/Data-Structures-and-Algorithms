#include<bits/stdc++.h>
using namespace std;

bool searchIn2DMatrix_brute(vector<vector<int>>matrix, int target){
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == target){
				return true;
			}
		}
	}
	return false;
}


// ----------------------------- better ----------------------------//

bool BinarySearch(vector<int>&arr, int target){
	int low = 0, high = arr.size() - 1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == target) return true;
		else if(target > arr[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return false;
}


bool searchIn2DMatrix_better(vector<vector<int>>matrix, int target){
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i = 0; i < n; i++){
		if(matrix[i][0] <= target && target <= matrix[i][m-1]){
			return BinarySearch(matrix[i], target);
		}
	}
	return false;
}



// ------------------------------ optimal ---------------------------//

bool searchIn2DMatrix_Optimal(vector<vector<int>>matrix, int target){
	int n = matrix.size();
	int m = matrix[0].size();

	int low = 0, high = (n*m)-1;

	while(low <= high){
		int mid = (low + high)/2;
		int row = mid / m;
		int col = mid % m;
		if(matrix[row][col] == target) return true;
		else if (matrix[row][col] < target) low = mid + 1;
		else high = mid - 1;
	}

	return false;
}

int main(){
	vector<vector<int>> matrix = {{3, 4, 7, 9},
								  {12, 13, 16, 18},
								  {20, 21, 23, 29}};

	int target = 23;

	// cout << searchIn2DMatrix_brute(matrix, target);

	// cout << searchIn2DMatrix_better(matrix, target);

	cout << searchIn2DMatrix_Optimal(matrix, target);
}
