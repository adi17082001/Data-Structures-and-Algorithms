class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>res;

        sort(arr.begin(), arr.end());

        vector<int>tempInterval = arr[0];
        for(auto it: arr){
            if(it[0] <= tempInterval[1]){
                //merge
                tempInterval[1] = max(it[1], tempInterval[1]);
            }
            else{
                res.push_back(tempInterval);
                tempInterval = it;
            }
        }
        res.push_back(tempInterval);
        return res;
    }
};
