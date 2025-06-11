class Solution {
public:
    int countNumberOfSetBits(int n){
        int ct = 0;
        while(n > 1){
            ct += (n & 1);
            n = n >> 1;
        }
        if(n == 1) ct +=1 ;
        return ct;
    }
    int minBitFlips(int start, int goal) {
        int ans  = start ^ goal;
        return countNumberOfSetBits(ans);
    }
};
