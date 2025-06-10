#include<bits/stdc++.h>
using namespace std;

int removeRightMostSetBit(int n){
	return (n & (n-1));
}

int main(){
	int n = 40;
	cout << removeRightMostSetBit(n);
}
