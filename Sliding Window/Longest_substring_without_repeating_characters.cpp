#include<bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingCharacters_brute(string &s){
	int n = s.size();
    int len = 0, maxLen = 0;

    for(int i = 0; i < n; i++){
        int hash[256] = {0};
        for(int j = i; j < n; j++){
            if(hash[s[j]] == 1) break;

            len = j - i + 1;
            maxLen = max(maxLen, len);
            hash[s[j]] = 1;
        }
    }
    return maxLen;
}

int longestSubstringWithoutRepeatingCharacters_optimal(string s) {
    int n = s.size();
    int hash[256] = {0};
    for(int i = 0; i < 256; i++){
        hash[i] = -1;
    }

    int l = 0, r = 0, maxLen = 0, len = 0;
    while(r < n){
        // if s[r] is present in the map
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }
        // if s[r] is not present in the map
        len = r - l + 1;
        maxLen = max(maxLen, len);
        hash[s[r]] = r;
        r++;
    }
    return maxLen;
}

int main(){
	string s = "cadbzabcd";

	cout << longestSubstringWithoutRepeatingCharacters_optimal(s);
}
