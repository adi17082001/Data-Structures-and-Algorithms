#include<bits/stdc++.h>
using namespace std;

int countNumberOfSetBits(int n){
	int ct = 0;
	while(n > 1){
		ct += (n & 1);
		n = n >> 1;
	}
	if(n == 1) ct +=1 ;
	return ct;
}

int main(){
	int n = 13;
	cout << countNumberOfSetBits(n);
}
