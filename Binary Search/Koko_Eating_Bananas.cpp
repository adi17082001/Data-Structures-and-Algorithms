#include<bits/stdc++.h>
using namespace std;

long func(vector<int>&arr, int hourly){
    long totalhrs = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        totalhrs += ceil((double)arr[i] / (double)hourly);
    }
    return totalhrs;
}

int maxElement(vector<int>&arr){
    int ans = INT_MIN;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        ans = max(arr[i], ans);
    }
    return ans;
}

int minEatingSpeed(vector<int>& arr, int h) {
    int low = 1, high = maxElement(arr), ans = INT_MAX;
    while(low <= high){
        int mid = (low + high)/2;
        long totalhrs = func(arr, mid);
        if(totalhrs <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}


int main(){
	vector<int>piles = {3,6,7,11};
	int h = 8;
	cout << minEatingSpeed(piles, h);
}
