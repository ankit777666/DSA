class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high) {
        vector<int> temp;
        int left=low; int right=mid+1;
        while(left<=mid && right<=high) {
            if(nums[left]<=nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high) {
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low; i<=high; i++)
            nums[i]=temp[i-low];
    }
    void mergeSort(vector<int>&nums, int low, int high) {
        if(low>=high)
            return;
        int mid=low+(high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    void sortLastMelements(vector<int>&nums, int n, int m) {
    	// Code here
    // 	vector<int> temp;
    // 	for(int i=n; i<n+m; i++)
    // 	    temp.push_back(nums[i]);
	    mergeSort(nums, n, n+m-1);
	   // int mid=n+m/2;
	   // merge(nums, 0, mid, n+m-1);
    	
    }
};