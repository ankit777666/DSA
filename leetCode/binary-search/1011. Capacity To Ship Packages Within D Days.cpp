class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity) {
        int sum=0, count=0;
        for(int i=0; i<weights.size(); i++) {
            if(sum+weights[i]<=capacity) {
                sum+=weights[i];
            }
            else {
                count++;
                sum=weights[i];
            }
            
        }
        count++;
        if(count<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxEle=INT_MIN, sum=0;
        for(int i=0; i<n; i++) {
            maxEle=max(maxEle, weights[i]);
            sum+=weights[i];
        }
        int low=maxEle, high=sum;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(isPossible(weights, days, mid)) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};