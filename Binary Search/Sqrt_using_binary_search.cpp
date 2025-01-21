#include<bits/stdc++.h>
using namespace std;


int sqrtUsingBinarySearch_brute(int n){
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if(i * i <= n){
			ans = i;
		}
		else{
			break;
		}
	}
	return ans;
}

// optimal - using binary search

int sqrtUsingBinarySearch(int n){
	int ans = 1;
	int low = 1, high = n;
	while(low <= high){
		int mid = (low + high)/2;
		if(mid * mid <= n){
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
	int n = 28;
	cout << sqrtUsingBinarySearch_brute(n);
}
