#include<bits/stdc++.h>
using namespace std;

// brute - linear search - O(N)

pair<int,int> firstAndLast(vector<int>&arr, int x){
	int n = arr.size();
	int first = -1, last = -1;
	for(int i = 0; i < n; i++){
		if(arr[i] == x){
			if(first == -1) first = i;
			last = i;
		}
	}
	pair<int,int>res = {first, last};
	return res;
}

// --------------------------------------------------------------

// better - B.S. - 2 * O(log N)

int lowerBound(vector<int> arr, int x) {
	// Write your code here
	int n = arr.size();
	int low = 0, high = n-1;
	int ans = n;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]>=x){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}

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

pair<int,int> firstAndLast(vector<int>&arr, int x){
	int n = arr.size();
	int lb = lowerBound(arr, x);
	if(lb == n || arr[lb] != x) return {-1,-1};
	return {lowerBound(arr,x), upperBound(arr,x) - 1};
}

// ------------------------------------------------------------------------

// Normal B.S. 

int firstOccurrence(vector<int>&arr, int x){
	int n = arr.size();
	int low = 0, high = n-1;
	int first = -1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == x){
			first = mid;
			high = mid - 1;
		}
		else if(arr[mid] < x){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return first;
}

int lastOccurrence(vector<int>&arr, int x){
	int n = arr.size();
	int low = 0, high = n-1;
	int last = -1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == x){
			last = mid;
			low = mid + 1;
		}
		else if(arr[mid] < x){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return last;
}

pair<int,int> firstAndLast(vector<int>&arr, int x){
	int first = firstOccurrence(arr, x);
	if(first == -1) return {-1,-1};
	int last = lastOccurrence(arr, x);
	return {first, last};
}

int main(){
	vector<int>arr = {2,4,6,8,8,8,11,13};
	int x = 8;
	pair<int,int> res = firstAndLast(arr, x);
	cout<<res.first<<" "<<res.second<<endl;
}
