#include<bits/stdc++.h>
using namespace std;

int func(vector<int>&arr, int pages){
	int students = 1, pagesStudent = 0;
	for(int i = 0; i < arr.size(); i++){
		if(pagesStudent + arr[i] <= pages){
			pagesStudent += arr[i];
		}else{
			students++;
			pagesStudent = arr[i];
		}
	}
	return students;
}

int bookAllocation_brute(vector<int>&arr, int m){
	// case where books cannot be allocated to all students
	if( m > arr.size()) return -1;

	int low = *max_element(arr.begin(), arr.end());
	int high = 0;
	for(int i = 0; i < arr.size(); i++){
		high += arr[i];
	}

	for(int pages = low; pages <= high; pages++){
		int cntStudents = func(arr, pages);
		if(cntStudents == m) return pages;
	}

	return -1;
}


int bookAllocation(vector<int>&arr, int m){
	// case where books cannot be allocated to all students
	if( m > arr.size()) return -1;

	int low = *max_element(arr.begin(), arr.end());
	// high = sum of array
	int high = 0;
	for(auto i: arr){
		high += i;
	}

	while(low <= high){
		int mid = (low + high)/2;
		int noOfStu = func(arr, mid);
		if(noOfStu > m) low = mid + 1;
		else high = mid - 1;
	}
	return low;
}

int main(){
	vector<int>arr = {25,46,28,49,24};
	int students = 4;

	// cout << bookAllocation_brute(arr, students);
	cout << bookAllocation(arr, students);
}
