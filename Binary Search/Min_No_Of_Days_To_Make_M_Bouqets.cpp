#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&bloomDay, int day, int m, int k) {
	int ct = 0, noOfB = 0;
	for(int i = 0; i < bloomDay.size(); i++) {
		if(bloomDay[i] <= day) {
			ct++;
		}
		else {
			noOfB += (ct / k);
			ct = 0;
		}
	}
	noOfB += (ct / k);
	return (noOfB >= m);
}


int minNoOfDaysToMakeMBouqets_brute(vector<int>&bloomDay, int m, int k){
	int mini = *min_element(bloomDay.begin(), bloomDay.end());
	int maxi = *max_element(bloomDay.begin(), bloomDay.end());

	for(int i = mini; i <= maxi; i++){
		if(isPossible(bloomDay, i, m, k)){
			return i;
		}
	}
	return -1;
}


int minNoOfDaysToMakeMBouqets(vector<int>&bloomDay, int m, int k){
	int mini = *min_element(bloomDay.begin(), bloomDay.end());
	int maxi = *max_element(bloomDay.begin(), bloomDay.end());

	int low = mini, high = maxi, ans = -1;
	while(low <= high){
		int mid = (low + high)/2;
		if(isPossible(bloomDay, mid, m, k)){
			ans = mid; 
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return ans;
}


int main() {
	vector<int> bloomDay = {7,7,7,7,13,11,12,7};

	int m = 2, k = 3;
	// cout << isPossible(bloomDay, 7, m, k);
	// cout << minNoOfDaysToMakeMBouqets_brute(bloomDay,m,k);
	cout << minNoOfDaysToMakeMBouqets(bloomDay, m, k);
}
