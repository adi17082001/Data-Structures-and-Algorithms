#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x){
	// Write your code here.
  int n = arr.size();
	int ans = n;
	int low = 0, high = n-1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] > x){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}	
	return ans;
	
}

int main(){
  vector<int>arr = {1,2,3,4,5,6,6,7};
  cout<< upperBound(arr, 6);
