#include<bits/stdc++.h>
using namespace std;


int numberOfDays(vector<int>&weights, int capacity){
	int n = weights.size();
	int days = 1, load = 0;
	for(int i = 0; i < n; i++){
		if(load + weights[i] > capacity){
			days = days + 1;
			load = weights[i];
		}
		else{
			load += weights[i];
		}
	}
	return days;
}

int leastCapacityToShip_brute(vector<int>&weights, int days){
	int n = weights.size();
	int maxi = *max_element(weights.begin(), weights.end());
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += weights[i];
	}

	for(int capacity = maxi; capacity <= sum; capacity++){
		int daysReq = numberOfDays(weights, capacity);
		if(daysReq <= days) return capacity;
	}

	return -1;
}

int leastCapacityToShip(vector<int>weights, int days){
	int n = weights.size();
	int maxi = *max_element(weights.begin(), weights.end());
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += weights[i];
	}

	int low = maxi, high = sum;
	while(low <= high){
		int mid = (low + high)/2;
		int noOfDays = numberOfDays(weights, mid);
		if(noOfDays <= days){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}	
	return low;
}

int main(){
	vector<int>weights = {1,2,3,4,5,6,7,8,9,10};
	int days = 5;
	
	// cout << leastCapacityToShip_brute(weights, days);
	cout << leastCapacityToShip(weights, days);

}
