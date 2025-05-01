class Solution {
public:
    const int M = 1e9+7;
    long long binaryExp(long long a, long long b){
        if(b == 0) return 1;
        long long res = binaryExp(a, b/2);
        if(b & 1){
            return (a * ((res * res) % M) % M); 
        }
        return (res * res) % M;
    }

    int countGoodNumbers(long long n) {
        long long ans = binaryExp(20, n/2);
        if(n % 2){
            ans = (ans * 5) % 1000000007;
        }
        return ans;
    }
};
