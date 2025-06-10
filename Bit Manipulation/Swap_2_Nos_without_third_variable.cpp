#include<bits/stdc++.h>
using namespace std;

void swapWithoutThird(int &a, int &b){
	a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
	int a = 5, b = 6;
	swapWithoutThird(a,b);
	cout << "after swapping" << endl;
	cout << "a = "<< a << " b = " << b;
}
