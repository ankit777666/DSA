class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        long long ans=0;
        while(low<high) {
            string str1=to_string(nums[low]);
            string str2=to_string(nums[high]);
            long long fin=stoi(str1+str2);
            ans+=fin;
            low++;high--;
        }
        if(nums.size()%2!=0)
            ans+=nums[nums.size()/2];
        return ans;
    }
};