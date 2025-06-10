class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        if (dividend == divisor) return 1;
        bool sign = true;

        if (dividend >= 0 && divisor < 0) sign = false;
        if (dividend <= 0 && divisor > 0) sign = false;

        long long n = abs((long long)dividend), d = abs((long long)divisor);
        long long quotient = 0;
        
        while (n >= d) {
            int ct = 0;
            while (n >= (d << (ct + 1))) {
                ct++;
            }
            quotient += (1LL << ct);
            n = n - (d << ct);
        }

        if (quotient >= (1LL << 31) && sign) {
            return INT_MAX;
        }
        if (quotient >= (1LL << 31) && !sign) {
            return INT_MIN;
        }
        return sign ? quotient : (-1 * quotient);
    }
};
