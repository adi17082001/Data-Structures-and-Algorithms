#include<bits/stdc++.h>
using namespace std;

class Data{
public:
	int start;
	int end;
	int pos;

	Data(){}   // default constructor - needed as when we do vector<Data> arr(n);
	           // The vector tries to create n default-constructed Data objects. 
	           // However, since you did not define a default (no-argument) constructor, it fails.

	Data(int s, int e, int p){
		start = s;
		end = e;
		pos = p;
	}
};

bool comp(Data val1, Data val2){
	return val1.end < val2.end;
}

int maximizeMeetings(vector<int>&start, vector<int>&end){
	int n = start.size();

	vector<Data> arr(n);

	for(int i = 0; i < n; i++){
		arr[i].start = start[i];
		arr[i].end = end[i];
		arr[i].pos = i + 1;
	}

	sort(arr.begin(), arr.end(), comp); // sort on the basis of end time

	int cnt = 1, freetime = arr[0].end;
	vector<int>ds = {arr[0].pos};

	for(int i = 1; i < n; i++){
		if(arr[i].start > freetime){
			cnt++;
			freetime = arr[i].end;
			ds.push_back(arr[i].pos);
		}
	}


	// return count or ds based on the question
	return cnt;
}

int main(){
	vector<int>start = {0,3,1,5,5,8};
	vector<int>end = {5,4,2,9,7,9};

	cout << maximizeMeetings(start, end);

}
