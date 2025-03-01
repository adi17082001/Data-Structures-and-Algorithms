#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &arr, int maxSum) {
    int n = arr.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + arr[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += arr[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = arr[i];
        }
    }
    return partitions;
}

int SplitArrayLargestSum(vector<int> &arr, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(arr, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << SplitArrayLargestSum(arr, k);

    return 0;
}

