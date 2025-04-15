bool isIsomorphic(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    if(n1 != n2) return false;
    map<char,char>m1, m2;
    for(int i = 0; i < n1; i++){
        if(m1[s1[i]] == 0 && m2[s2[i]] == 0){
            m1[s1[i]] = s2[i];
            m2[s2[i]] = s1[i];
        }
        if(m1[s1[i]] != s2[i] && m2[s2[i]] != s1[i]){
            return false;
        }
    }
    return true;
}
