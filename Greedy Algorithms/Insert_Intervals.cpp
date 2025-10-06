class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = arr.size();

        // Add all intervals before newInterval
        while(i < n && arr[i][1] < newInterval[0]) {
            res.push_back(arr[i]);
            i++;
        }

        // Merge overlapping intervals
        while(i < n && arr[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], arr[i][0]);
            newInterval[1] = max(newInterval[1], arr[i][1]);
            i++;
        }
        res.push_back(newInterval);

        // Add the remaining intervals
        while(i < n) {
            res.push_back(arr[i]);
            i++;
        }

        return res;
    }
};
