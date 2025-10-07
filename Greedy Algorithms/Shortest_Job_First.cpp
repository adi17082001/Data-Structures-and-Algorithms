#include<bits/stdc++.h>
using namespace std;

// get the average waiting time
int sjfAvgWaitTime(vector<int>&arr){
	sort(arr.begin(), arr.end());
	int t = 0, waitTime = 0;

	for(int i = 0; i < arr.size(); i++){
		waitTime += t;
		t += arr[i];
	}
	return (waitTime/arr.size());
}

int main(){
	vector<int>bt = {4,3,7,1,2};
	cout << sjfAvgWaitTime(bt);
}
