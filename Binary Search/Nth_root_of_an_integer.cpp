#include<bits/stdc++.h>
using namespace std;


// -------------- brute ----------------------------

int f(int i, int n){
	int ans = 1;
	for(int j = 1; j <= n; j++){
		ans = ans * i;
	}
	return ans;
}

int nthRoot_brute(int n, int m){
	for(int i = 1; i <= m; i++){
		if(f(i,n) == m){
			return i;
		}
		else if(f(i,n) > m){
			break;
		}
	}
	return -1;
}

// --------------------------------------------------------------

// optimal

int func(int mid, int n, int m){
	long long ans = 1;
	for(int i = 1; i <= n; i++){
		ans = ans * mid;
		if( ans > m) return 2; // to avoid overflow
	}
	if(ans == m) return 1;
	return 0;
}

int nthRoot(int n, int m){
	int low = 1, high = m;
	while(low <= high){
		int mid = (low + high)/2;
		int midN = func(mid, n, m);
		if(midN == 1) return mid;
		else if(midN == 0) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}


int main(){
	int n = 5, m = 3125;

	cout << nthRoot(n,m);
}
