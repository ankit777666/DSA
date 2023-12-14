class Solution {
public:
    int maxWater(int arr[], int n) {
            // code here 
        int left[n];
        int right[n];
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        
        int water = 0;
        
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],arr[i]);
        }
        
        for(int i=0;i<n;i++){
            water += (min(left[i],right[i]) - arr[i]);
        }
        
        return water;
    }
    /**
     *  int l=0,r=n-1;
        int lm=0,rm=0;
        long long rst=0;
        while(l<=r){
            if(lm<rm){
                rst+=max(0,lm-arr[l]);
                lm=max(lm,arr[l++]);
            }
            else{
                rst+=max(0,rm-arr[r]);
                rm=max(rm,arr[r--]);
            }
        }
        return rst;
    */
};