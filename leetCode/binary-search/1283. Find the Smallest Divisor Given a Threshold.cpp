class Solution {
public:


    bool isPossible(vector<int>& nums, int threshold, int mid) {
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=ceil(nums[i]/(double)mid);
        }
        if(sum<=threshold)
            return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1, high=*max_element(nums.begin(), nums.end());

        while(low<=high) {
            int mid=low+(high-low)/2;
            if(isPossible(nums,threshold, mid)) {
                
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};