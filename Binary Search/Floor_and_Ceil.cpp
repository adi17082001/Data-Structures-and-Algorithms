int Floor(vector<int>&arr, int n, int x){
	int ans = -1;
	int low = 0, high = n-1;
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] <= x){
			ans = arr[mid];
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return ans;
}

int Ceil(vector<int>&arr, int n, int x){
	int ans = -1;
	int low = 0, high = n - 1;
	while(low <= high){
		int mid  = (low + high)/2;
		if(arr[mid] >= x){
			ans = arr[mid];
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int floor = Floor(a,n,x);
	int ceil = Ceil(a,n,x);
	pair<int,int>ans = {floor,ceil};
	return ans;
}
