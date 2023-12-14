class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        int i=0, j=n-1;
        int ans=0;
        while(i<j) {
            if(height[i]<height[j]) {
                ans=max(ans, (j-i-1)*height[i]);
                i++;
            }
            else if(height[j]<height[i]) {
                ans=max(ans, (j-i-1)*height[j]);
                j--;
            }
            else {
                ans=max(ans, (j-i-1)*height[j]);
                i++;j--;
            }
        }
        return ans;
        
    }   
};