#include<bits/stdc++.h>
using namespace std;

vector<int> maximumSumSubarray(vector<int>&arr){
	vector<int>indices;
	int ansStart = -1, ansEnd = -1, start = -1;
	int maxi = INT_MIN;
	int sum = 0;
	for(int i = 0; i < arr.size(); i++){
		if(sum == 0) start = i;
		sum += arr[i];
		if(sum > maxi){
			maxi = sum;
			ansStart = start;
			ansEnd = i;
		}
		if(sum < 0){
			sum = 0;
		}
	}
	indices.push_back(ansStart);
	indices.push_back(ansEnd);
	return indices;
}

int main(){
	vector<int>arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	vector<int>ind = maximumSumSubarray(arr);
	for(int i = ind[0]; i <= ind[1]; i++){
		cout << arr[i] << " ";
	}
}
