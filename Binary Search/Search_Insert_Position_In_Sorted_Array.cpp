#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int x) {
      // return the lower bound i.e. smallest index such that arr[ind] >= x
      int ans = nums.size();
      int low = 0, high = nums.size()  - 1;
      while(low <= high){
          int mid = (low + high)/2;
          if(nums[mid] >= x){
              ans = mid;
              high = mid - 1;
          }
          else{
              low = mid + 1;
          }
      }
      return ans;
  }

int main(){
  vector<int>arr = {1,3,5,6};
  cout<<searchInsert(arr,2);
}
