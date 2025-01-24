bool isPossible(vector<int>&arr, int day, int m, int k){
	int ct = 0, noOfBouqets = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] <= day){
			ct++;
		}
		else{
			noOfBouqets += (ct / k);
		}
	}
	noOfBouqets += (ct / k);
	return noOfBouqets >= m;
}



int minNoOfDaysToMakeMBouquets(vector<int>& bloomDay, int m, int k) {
    int mini = *min_element(bloomDay.begin(), bloomDay.end());
    int maxi = *max_element(bloomDay.begin(), bloomDay.end());

    int low = mini, high = maxi, ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(isPossible(bloomDay, mid, m, k)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
