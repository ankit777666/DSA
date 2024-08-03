class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0, rightSum=0;
        int ans;
        for(int i=0;i<k; i++) 
          leftSum+=cardPoints[i];
        ans=leftSum;
        int rIndex=cardPoints.size()-1;
        for(int i=k-1; i>=0; i--) {
          leftSum-=cardPoints[i];
          rightSum+=cardPoints[rIndex--];
          ans=max(ans, leftSum+rightSum);
        }
        return ans;
    }
};