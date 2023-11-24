class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans(n+1,0);
        int repeating = 0; int missing = 0;
        
        for(int i=0; i<n; i++) {
            ans[arr[i]]++;
        }
        for(int i=1; i<n+1; i++) {
            if(ans[i] == 2)
                repeating = i;
            if(ans[i] == 0)
                missing = i;
        }
        
       
        
        return {repeating, missing};
        
    }
};