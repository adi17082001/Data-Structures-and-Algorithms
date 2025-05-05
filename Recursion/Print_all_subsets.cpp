#include<bits/stdc++.h>
using namespace std;

 void solve(vector<int>nums,vector<int> op, vector<vector<int>> &m){ // m ko by address paas kiye as jo bhi changes m me ho wo vector wale fn me reflect ho and nums aur op ko pass by value kiye uska changes vector fn me reflect nahi hoga 
    if(nums.size()==0){
        m.push_back(op);
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    op2.push_back(nums[0]);
    nums.erase(nums.begin()+0);
    solve(nums,op1, m);
    solve(nums,op2, m);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> m;
    vector<int>op;
    solve(nums,op,m);
    return m;
        
}

int main(){
	vector<int>nums = {1,2,3};
	vector<vector<int>>res = subsets(nums);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			cout << res[i][j] <<" ";
		}
		cout << endl;
	}
}
