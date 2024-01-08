class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int ans=INT_MIN;
        while(i<j) {
            int h=min(height[j],height[i]);
            ans=max(ans, (j-i)*h);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};