#include<bits/stdc++.h>
using namespace std;

// brute approach is easy to understand. focus majorly on brute

int trappingRainWater_brute(vector<int>&arr){
	int n = arr.size();

	//prefixMax and suffixMax - for leftMax and rightMax;
	vector<int> prefixMax(n), suffixMax(n);

	// calculate prefixMax
	prefixMax[0] = arr[0];
	for(int i = 1; i < n; i++){
		prefixMax[i] = max(prefixMax[i-1], arr[i]);
	}

	// calculate suffixMax
	suffixMax[n-1] = arr[n-1];
	for(int i = n-2; i >= 0; i--){
		suffixMax[i] = max(suffixMax[i+1], arr[i]);
	}

	int total = 0;
	for(int i = 0; i < n; i++){
		int leftMax = prefixMax[i];
		int rightMax = suffixMax[i];

		if(arr[i] < leftMax && arr[i] < rightMax){
			total = total + min(leftMax, rightMax) - arr[i];
		}
	}

	return total;

}

int trappingRainWater_optimal(vector<int>&arr){
	int n = arr.size();
	int leftMax = 0, rightMax = 0, total = 0;
	int l = 0, r = n - 1;
	while(l < r){
		if(arr[l] < arr[r]){
			if(leftMax > arr[l]){
				total += leftMax - arr[l];
			}
			else{
				leftMax = arr[l];
			}

			l = l + 1;
		}
		else{
			if(rightMax > arr[r]){
				total += rightMax - arr[r];
			}
			else{
				rightMax = arr[r];
			}

			r = r - 1;
		}
	}
	return total;
}

int main(){
	vector<int>arr = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << trappingRainWater_optimal(arr);
}
