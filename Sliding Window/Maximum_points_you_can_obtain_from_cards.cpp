int maxScore(vector<int>& nums, int k) {
	int lsum = 0, rsum = 0, maxSum = 0;

	for(int i = 0; i <= k-1; i++){
		lsum += nums[i];
	}
	maxSum = lsum;

	int rIndex = nums.size() - 1;

	for(int i = k-1; i>= 0; i--){
		lsum = lsum - nums[i];
		rsum = rsum + nums[rIndex];
		rIndex = rIndex - 1;

		maxSum = max(maxSum, (lsum + rsum));
	}
	return maxSum;
}
