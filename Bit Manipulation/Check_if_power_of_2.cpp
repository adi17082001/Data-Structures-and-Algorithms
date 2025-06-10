#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n){
	if((n & (n-1)) == 0) return true;
	return false;
}

int main(){
	int n = 64;
	cout << isPowerOf2(n);
}
