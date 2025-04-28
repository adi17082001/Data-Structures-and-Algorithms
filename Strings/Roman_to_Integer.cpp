#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char,int>mpp{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int res = 0;
    for(int i = 0; i < s.size(); i++){
        if(mpp[s[i]] < mpp[s[i+1]]){
            res = res - mpp[s[i]];
        }
        else{
            res = res + mpp[s[i]];
        }
    }
        
    return res;
}

int main(){
  string num = "MIX";
  cout << romanToInt(num);
}
