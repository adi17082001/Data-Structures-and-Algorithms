#include<bits/stdc++.h>
using namespace std;


int findSmallestDivisorWithGivenThreshold_brute(vector<int>&arr, int threshold){
	int n = arr.size();
	int maxi = *max_element(arr.begin(), arr.end());
	for(int d = 1; d <= maxi; d++){
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += (double)ceil((double)arr[i] / (double)d);   // this is important for ceil...remember. 
		}
		if(sum <= threshold) return d;
	}
	return -1;
}

int sumDivByD(vector<int>&arr, int d){
	int n = arr.size();
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += (double)ceil((double)arr[i] / (double)d);   // this is important for ceil...remember to make sure no cast errors
	}
	return sum;
}

int findSmallestDivisorWithGivenThreshold(vector<int>&arr, int threshold){
	int n = arr.size();
	if(n > threshold) return -1;
	int maxi = *max_element(arr.begin(), arr.end());
	int ans = -1;
	int low = 1, high = maxi;
	while(low <= high){
		int mid = (low + high)/2;
		int sum = sumDivByD(arr, mid);
		if(sum <= threshold){
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
	vector<int>arr = {1,2,5,9};
	int threshold = 6;

	// cout << findSmallestDivisorWithGivenThreshold_brute(arr, threshold);
	cout << findSmallestDivisorWithGivenThreshold(arr, threshold);
}
