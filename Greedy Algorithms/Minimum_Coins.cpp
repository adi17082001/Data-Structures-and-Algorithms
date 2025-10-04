#include<bits/stdc++.h>
using namespace std;


vector<int> minimumCoins(int v){
	vector<int>res;
	vector<int>deno = {1,2,5,10,20,50,100,500,1000};
	int n = deno.size();

	for(int i = n-1; i >= 0; i--){
		while(v >= deno[i]){
			v = v - deno[i];
			res.push_back(deno[i]);
		}
	}
	return res;
}

int main(){
	int v = 49;
	vector<int> res = minimumCoins(v);
	for(int i: res){
		cout << i <<" ";
	}
}
