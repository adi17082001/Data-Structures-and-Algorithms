// brute
int numberOfSubstrings(string s) {
    int ct = 0;
    for(int i = 0; i < s.size(); i++){
        int hash[3] = {0};
        for(int j = i; j < s.size(); j++){
            hash[s[j] - 'a'] = 1;
            if((hash[0] + hash[1] + hash[2]) == 3){
                ct++;
            }
        }
    }
    return ct;
}

// optimal
int numberOfSubstrings(string s){
	int lastseen[3] = {-1,-1,-1};
    int ct = 0;
    for(int i = 0; i < s.size(); i++){
        lastseen[s[i] - 'a'] = i;
        if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
            ct = ct + ( 1 + min(min(lastseen[0], lastseen[1]), lastseen[2]));
        }
    }
    return ct;
}
