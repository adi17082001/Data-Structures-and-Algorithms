class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if (n < m) return ""; // Early return if s is smaller than t

        // Frequency map for characters in t
        int hash[256] = {0};
        for (int i = 0; i < m; i++) {
            hash[t[i]]++; // Update frequency for string t
        }

        // Sliding window variables
        int l = 0, r = 0, ct = 0, minlen = INT_MAX, sIndex = -1;

        // Sliding window on s
        while (r < n) {
            // If current character in s[r] is required, count it
            if (hash[s[r]] > 0) {
                ct++;
            }
            hash[s[r]]--; // Decrease the count of the current character
            r++;

            // When all characters from t are matched in the window
            while (ct == m) {
                // Update result if we found a smaller window
                if (r - l < minlen) {
                    minlen = r - l;
                    sIndex = l;
                }

                // Shrink the window by moving l to the right
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    ct--;
                }
                l++;
            }
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};
