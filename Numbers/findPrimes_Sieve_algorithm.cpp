#include<bits/stdc++.h>
using namespace std;
//const int N = 1e5+10;
// Sieve Algorithm  -> find primes from 1 to n

int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        int ct = 0;
        int primes[n+1];
        for(int i = 2; i < n; i++){
            primes[i] = 1;
        }

        for(int i = 2; i < sqrt(n); i++){
            if(primes[i] == 1){
                for(int j = i*i; j < n; j+=i){
                    primes[j] = 0;
                }
            }
        }
        for(int i = 2; i < n; i++){
            if(primes[i] == 1) ct++;
        }
        return ct;
    }

vector<int>Primes(int n){
	vector<int>res;
	vector<bool>isPrime(n+1,1);
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i<=n;i++){
		if(isPrime[i] == true){
			for(int j=2*i;j<=n;j++){
				if(j%i==0) isPrime[j] = false;
			}
		}
	}
	for(int i=0;i<n+1;i++){
		if(isPrime[i]) res.push_back(i);
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int>primes = Primes(n);
	for(auto i: primes){
		cout<<i<<endl;
	}
}
