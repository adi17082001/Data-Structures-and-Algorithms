#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>&v, int temp){
	if(v.size() == 0 || v[v.size() - 1] <= temp){
		v.push_back(temp);
		return;
	}
	int val = v[v.size() - 1];
	v.pop_back();
	insert(v, temp);
	v.push_back(val);
	return;
}

void recurSort(vector<int>&v){
	if(v.size() == 1) return;
	int temp = v[v.size() - 1];
	v.pop_back();
	recurSort(v);
	insert(v, temp);
}


int main(){
	vector<int>v = {2,3,5,4,7,6,9};
	recurSort(v);
	for(auto i: v){
		cout << i << " ";
	}
}
