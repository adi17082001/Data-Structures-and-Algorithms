// brute
class Solution {
public:
    bool f(string s, int ind, int ct){
        if(ct < 0) return false;
        if(ind == s.size()) return (ct == 0);
        if(s[ind] == '('){
            f(s, ind+1, ct+1);
        }
        if(s[ind] == ')'){
            f(s, ind+1, ct-1);
        }
        return(f(s,ind+1, ct+1) || f(s, ind+1, ct-1) || f(s, ind+1, ct));
    }
    bool checkValidString(string s) {
        return f(s, 0, 0);
    }
};

// optimal
class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                mini = mini + 1;
                maxi = maxi + 1;
            }
            else if(s[i] == ')'){
                mini = mini - 1;
                maxi = maxi - 1;
            }
            else{ // if asterisk
                mini = mini - 1;
                maxi = maxi + 1;
            }
            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }

        return (mini == 0);
    }
};
