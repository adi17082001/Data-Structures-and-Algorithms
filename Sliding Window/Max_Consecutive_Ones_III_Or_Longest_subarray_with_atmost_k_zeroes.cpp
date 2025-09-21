#include<bits/stdc++.h>
using namespace std;

int longestOnes_brute(vector<int>& arr, int k) {
    int maxLen = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        int zeroes = 0;
        for(int j = i; j < n; j++){
            if(arr[j] == 0) zeroes++;

            if(zeroes <= k){
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            }
            else{
                break;
            }
        }
    }

    return maxLen;
}

int longestOnes_optimal(vector<int>& nums, int k) {
    int maxLen = 0, l = 0, r = 0, zero = 0;
    int n = nums.size();
    while(r < n){
        if(nums[r] == 0) zero++;

        while(zero > k){
            if(nums[l] == 0) zero--;
            l++;
        }
        if(zero <= k){
            int len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }
    return maxLen;
}


int main(){
	vector<int>arr = {1,1,1,0,0,0,1,1,1,1,0};
	int k = 2;
	// cout << longestOnes_brute(arr, k);
	cout << longestOnes_optimal(arr, k);
}
