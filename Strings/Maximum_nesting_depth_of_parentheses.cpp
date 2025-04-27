#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int res = 0;
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            curr++;
            if( curr > res) res = curr;
        }
        else if(s[i] == ')'){
            curr--;
        }
    }
    return res;
}

int main(){
  string s = "(1+(2*3)+((8)/4))+1";
  cout << maxDepth(s);
}
