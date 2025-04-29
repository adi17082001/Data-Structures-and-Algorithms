#include<bits/stdc++.h>
using namespace std;

int countDistinct(string &s, int k){
	int n = s.size();
	int ans = 0;

	for(int i = 0; i < n; i++){
		vector<bool>cnt(26, 0);
		int distinct = 0;
		for(int j = i; j < n; j++){
			if(cnt[s[j] - 'a'] == false){
				cnt[s[j] - 'a'] = true;
				distinct++;
			}
			if(distinct == k) ans++;
		}
	}
	return ans;
}

int main(){
	string s = "aba";
	cout << countDistinct(s,2);
}
