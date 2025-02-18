#include<bits/stdc++.h>
using namespace std;

//------------------------------ better ---------------------------//

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

bool searchIn2DMatrix2_better(vector<vector<int>>matrix, int target){
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i = 0; i < n; i++){
		int ind = BinarySearch(matrix[i], target);
		if(ind != -1) return true;
	}
	return false;
}


//--------------------------- optimal ------------------------------//

bool searchIn2DMatrix2_Optimal(vector<vector<int>>&matrix, int target){
	int n = matrix.size();
	int m = matrix[0].size();

	int row = 0, col = m-1;
	while(row < n && col >= 0){
		if(matrix[row][col] == target) return true;
		else if(matrix[row][col] < target) row++;
		else col--;
	}

	return false;
}



int main(){
	vector<vector<int>>matrix = {{1, 4, 7, 11, 15},
								 {2, 5, 8, 12, 19},
								 {3, 6, 9, 16, 22},
								 {10, 13, 14, 17, 24},
								 {18, 21, 23, 26, 30}};

	int target = 23;

	// cout << searchIn2DMatrix2_better(matrix, target);

	cout << searchIn2DMatrix2_Optimal(matrix, target);
}
