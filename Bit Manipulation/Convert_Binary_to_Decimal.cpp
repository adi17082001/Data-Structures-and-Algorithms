#include<bits/stdc++.h>
using namespace std;

int convertBinaryToDecimal(string &str){
	int len = str.size();
	int powerOf2 = 1, num = 0;

	for(int i = len - 1; i >= 0; i--){
		if(str[i] == '1'){
			num = num + powerOf2;
		}
		powerOf2 = powerOf2 * 2;
	}
	return num;
}


int main(){
	string str = "11001";
	cout << convertBinaryToDecimal(str);
}
