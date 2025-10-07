class Solution {
public:
    static bool comp(vector<int>&val1, vector<int>&val2){
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int ct = 1, lastEndTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= lastEndTime){
                ct = ct + 1;
                lastEndTime = intervals[i][1];
            }
        }
        return n - ct;
    }
};
