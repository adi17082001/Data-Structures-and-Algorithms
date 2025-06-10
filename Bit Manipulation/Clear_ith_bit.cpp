#include<bits/stdc++.h>
using namespace std;

int clearIthBit(int n, int i){
	return (n & (~(1 << i)));
}

int main(){
	int n = 13,  i = 2;
	cout << clearIthBit(n, i);
}
