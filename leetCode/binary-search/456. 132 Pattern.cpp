class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int thirdEle=INT_MIN;
        stack<int>s;
        for(int i=n-1; i>=0; i--) {
            if(nums[i]<thirdEle)
                return true;
            while(!s.empty() && s.top()<nums[i]) {
                thirdEle=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};