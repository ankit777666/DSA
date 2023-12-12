class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
        // code here 
        int i=0, j=0;
        int sum1=0, sum2=0;
        int ans=INT_MIN;
        unordered_map<int,int> umap;
        
        while(j<n) {
            
            sum1+=arr1[j];
            sum2+=arr2[j];
            
            int diff=sum1-sum2;
            if(diff==0) ans=j+1;
            if(umap.find(diff)==umap.end()) {
                umap[diff]=j;
            }
            if(umap.find(diff)!=umap.end()) {
                ans=max(ans,j-umap[diff]);
            }
            j++;
            
        }
        return ans;
    }
};