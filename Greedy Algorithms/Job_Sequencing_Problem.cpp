#include <bits/stdc++.h>
using namespace std;

class Job{
public:
    int id;
    int deadline;
    int profit;

    Job(){}

    Job(int i, int d, int p){
        id = i;
        deadline = d;
        profit = p;
    }
};

bool comp(Job val1, Job val2){
    return val1.profit > val2.profit;
}

pair<int,int> jobSequencing(vector<Job>&arr){
    sort(arr.begin(), arr.end(), comp);
    int totalProfit = 0, ct = 0, maxDeadline = -1, n = arr.size();

    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    vector<int>hash(maxDeadline+1, -1);

    for(int i = 0; i < n; i++){
        for(int j = arr[i].deadline; j >= 1; j--){
            if(hash[j] == -1){
                ct = ct + 1;
                hash[j] = arr[i].id;
                totalProfit = totalProfit + arr[i].profit;
                break;
            }
        }
    }
    return {ct, totalProfit};
}

int main(){
     vector<Job> jobs = {
        Job(1, 2, 100),
        Job(2, 1, 19),
        Job(3, 2, 27),
        Job(4, 1, 25),
        Job(5, 3, 15)
    };

    pair<int, int> result = jobSequencing(jobs);

    cout << "Number of Jobs Done: " << result.first << endl;
    cout << "Total Profit: " << result.second << endl;
}
