class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(), skill.end());
        long long sum=0;
        long long ans=0;
        
        if(n==1) 
            return skill[0];
        if(n==2)
            return skill[0]*skill[1];
        sum=skill[n/2-1]+skill[n/2];
        

        int low=0, high=n-1;
        while(low<high) {
            if(skill[low]+skill[high]==sum) {
                ans+=skill[low]*skill[high];
            }
            else {
                return -1;
            }
            low++;high--;
        }
        return ans;
    }
};