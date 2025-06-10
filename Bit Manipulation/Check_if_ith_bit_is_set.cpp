#include<bits/stdc++.h>
using namespace std;

bool isIthBitSet(int n, int i){
	if((n & (1 << i)) != 0){
		return true;
	}
	return false;
}

int main(){
	int n = 13, i = 2;
	cout << isIthBitSet(n,i);
}
