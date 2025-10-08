class Solution {
public:
    int climbStairs(int n) {
        // recursive
        // if(n == 0) return 1;
        // if(n == 1) return 1;

        // int left = climbStairs(n-1);
        // int right = climbStairs(n-2);

        // return left + right;

        // vector<int>dp(n+1, -1);
        // if(n == 0 || n == 1) return 1;
        // if(dp[n] != -1) return dp[n];
        // dp[n] = climbStairs(n-1) + climbStairs(n-2);
        // return dp[n];

        // 0th step -> prev2 = 1;
        // 1st step -> prev = 1;
        int prev2 = 1, prev = 1;
        for(int i = 2; i <= n; i++){
            int curri = prev2 + prev;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
