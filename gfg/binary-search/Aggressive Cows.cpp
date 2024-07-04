class Solution {
public:
    bool isPossible(int n, int k, vector<int> &stalls, int mid) {
        int count=1, last=stalls[0];
        for(int i=1; i<n; i++) {
            if(stalls[i]-last>=mid) {
                count++;
                last=stalls[i];
            }
            if(count>=k)
                return true;
        }
        
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int low=1, high=stalls[n-1]-stalls[0];
        
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(isPossible(n,k,stalls,mid)) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return high;
    }
};