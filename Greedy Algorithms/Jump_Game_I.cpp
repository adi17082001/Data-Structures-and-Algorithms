#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>&arr){
	int maxIndex = 0;
	for(int i = 0; i < arr.size(); i++){
		if(i > maxIndex) return false;
		maxIndex = max(maxIndex, i + arr[i]);
	}
	return true;
}


int main(){
	vector<int>arr = {1,2,4,1,1,0,2,5};

	cout << canJump(arr);
}
