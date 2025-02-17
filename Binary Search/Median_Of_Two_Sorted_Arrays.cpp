#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays_brute(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    double ans = 0;
    vector<int>arr3;
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i++]);
        }
        else{
            arr3.push_back(arr2[j++]);
        }
    }
    while(i < n1) arr3.push_back(arr1[i++]);
    while(j < n2) arr3.push_back(arr2[j++]);

    int n = n1 + n2;
    if(n%2 == 1) ans = (double)arr3[n/2];
    else{
        ans = (double)(((double)arr3[n/2] + (double)arr3[n/2 - 1])/2);
    }

    return ans;
}

double findMedianSortedArrays_better(vector<int>&arr1, vector<int>&arr2){
    //size of two given arrays:
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;   // elements at index ind1 and ind2

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            if (cnt == ind1) ind1el = arr1[i];
            if (cnt == ind2) ind2el = arr1[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = arr2[j];
            if (cnt == ind2) ind2el = arr2[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = arr1[i];
        if (cnt == ind2) ind2el = arr1[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = arr2[j];
        if (cnt == ind2) ind2el = arr2[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}


double findMedianSortedArrays_Optimal(vector<int>&a, vector<int>b){
    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;
    if(n1 > n2) return findMedianSortedArrays_Optimal(b, a);  // make sure you run BS on smaller array

    int low = 0, high = n1;
    int left = (n1 + n2 + 1)/2;
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if( l1 <= r2 && l2 <= r1){
            if(n % 2 == 1) return max(l1, l2);
            return ((double)(max(l1,l2) +  min(r1,r2))) / 2.0;
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;
}



int main(){
    vector<int>arr1 = {1, 3, 4, 7, 10, 13};
    vector<int>arr2 = {2, 3, 6, 15};

    // cout << findMedianSortedArrays_brute(arr1, arr2);
    // cout << findMedianSortedArrays_better(arr1, arr2);
    cout << findMedianSortedArrays_Optimal(arr1, arr2);
}
