#include <bits/stdc++.h> 

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int>&arr, int low, int mid, int high){
	int ct = 0;
	int right = mid + 1;
	for(int i = low; i <= mid; i++){
		while(right <= high && arr[i] > 2*arr[right]){
			right++;
		}
		ct += (right - (mid + 1));
	}
	return ct;
}

int mergeSort(vector<int> &arr, int low, int high) {
	int ct = 0;
    if (low >= high) return ct;
    int mid = (low + high) / 2 ;
    ct += mergeSort(arr, low, mid);  // left half 
    ct += mergeSort(arr, mid + 1, high); // right half
  // adding to ct for every returned merge sort (above) + the current one (as below)
	  ct += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);  // merging sorted halves
	return ct;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	return mergeSort(arr, 0, n-1);

}
