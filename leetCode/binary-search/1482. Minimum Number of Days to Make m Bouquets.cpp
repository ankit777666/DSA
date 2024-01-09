class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int mid, int m, int k) {
        int count=0, target=0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i]<=mid) {
                count++;
            }
            else {
                target+=count/k;
                count=0;

            }
        }
        target+=count/k;
        if(target>=m)
            return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*(long)k>n) return -1;
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay, mid, m ,k)) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};