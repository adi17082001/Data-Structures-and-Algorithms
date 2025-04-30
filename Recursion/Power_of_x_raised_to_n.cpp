#include<bits/stdc++.h>
using namespace std;

// brute force
double pow(double x, int n){
	// if n is negative, convert it to positive.
	// to handle overflow, use long long
	long long power = (long long)(abs(n));
	double ans = x;
	for(int i = 1; i <= power; i++){
		ans = ans * x;
	}
	if(n < 0){
		double result = 1 / ans;
		return result;
	}
	return ans;
}

// optimal
double myPow(double x, int n) {
    double ans = 1.0;
    long nn = n;
    if(nn < 0){
        nn = -1 * nn;
    }
    while(nn > 0){
        if(nn % 2 == 1){
            ans = ans * x;
            nn = nn - 1;
        }
        else{
            x = x * x;
            nn = nn / 2;
        }
    }
    if(n < 0) ans = 1.0 / ans;
    return ans;
}

int main(){
  cout << pow(11,33);
}
