#include<bits/stdc++.h>
using namespace std;


// iterative

int BinarySearch(vector<int>&arr, int target){
	int low = 0, high = arr.size() - 1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == target) return mid;
		else if(target > arr[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

// recursive

int BinarySearch(vector<int>&arr, int low, int high, int target){
	if( low > high) return -1;
	int mid = (low + high)/2;
	if(arr[mid] == target) return mid;
	else if(target > arr[mid]) return BinarySearch(arr, mid+1, high, target);
	else return BinarySearch(arr, low, mid-1, target);
}


int main(){
	vector<int>&arr = {1,2,3,4,5,6,7,8,9};
	return BinarySearch(arr, 0, arr.size()-1, 6);
}