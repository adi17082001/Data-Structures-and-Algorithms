string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    int n = strs.size();
    sort(strs.begin(), strs.end());
    string s1 = strs[0];
    string s2 = strs[n-1];

    int i = 0, j = 0;
    while(i < s1.length() && j < s2.length()){
        if(s1[i] == s2[i]){
            ans += s1[i];
            i++;
            j++;
        }
        else{
            break;
        }
    }
    return ans;
}
