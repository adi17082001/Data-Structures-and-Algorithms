#include<bits/stdc++.h>
using namespace std;


bool canWePlace(vector<int>&arr, int dist, int cows){
	int n = arr.size();
	int cntCows = 1, lastCow = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] - lastCow >= dist){
			cntCows++;
			lastCow = arr[i];
		}
		if(cntCows >= cows) return true;
	}
	return false;
}


int aggressiveCows_brute(vector<int>&arr, int cows){
	int n = arr.size();
	sort(arr.begin(), arr.end());
	int maxi = *max_element(arr.begin(), arr.end());
	int mini = *min_element(arr.begin(), arr.end());

	for(int i = 1; i <= (maxi - mini); i++){
		if(canWePlace(arr, i, cows) == true){
			continue;
		}
		else{
			return (i-1);
		}
	}
	return -1;
}


int aggressiveCows(vector<int>&arr, int cows){
	int n = arr.size();
	int ans = -1;
	sort(arr.begin(), arr.end());
	int low = 0, high = arr[n-1] - arr[0];
	while(low <= high){
		int mid = (low + high)/2;
		if(canWePlace(arr, mid, cows) == true){
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return ans;
}


int main(){
	vector<int>arr = {0,3,4,7,9,10};
	int cows = 4;
	// cout << aggressiveCows_brute(arr, cows);
	cout << aggressiveCows(arr, cows);
}
