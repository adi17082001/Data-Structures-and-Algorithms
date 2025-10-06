#include <bits/stdc++.h>
using namespace std;

int minNumberOfPlatforms(vector<int>&arr, vector<int>&dep){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0, ct = 0, maxCt = 0, n = arr.size();

    while(i < n){
        if(arr[i] <= dep[j]){
            ct = ct + 1;
            i = i + 1;
        }else{
            ct = ct - 1;
            j = j + 1;
        }
        maxCt = max(maxCt, ct);
    }
    return maxCt;
}

int main(){
    vector<int>arr = {900, 945,955,1100,1500,1800};
    vector<int>dep = {920,1200,1130,1150,1900,2000};

    cout << minNumberOfPlatforms(arr, dep);

}
