class Solution {
public:
    long long util(vector<int>& piles, long long mid) {
        long long target=0;
        for(int i=0; i<piles.size(); i++) {
            target+=ceil((double)piles[i]/(double)mid);
        }
        return target;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long low=1;
        long long high=*max_element(piles.begin(), piles.end());
        // int ans=high;
        while(low<=high) {
            long long mid=low+(high-low)/2;
            if(util(piles, mid)<=h) {
                // ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};