class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int ans = 0;
        for(int i=0;i<ages.size();i++){
            int x = ages[i];
            int y = x/2 + 7;

            if(y >= x) continue;
            auto it = upper_bound(ages.begin() , ages.end() , y) - ages.begin();
            auto it2 = upper_bound(ages.begin(), ages.end() , x) - ages.begin();
            if(it < i){ans += (i - it);}
            if(it2 > i) ans += (it2 - i - 1);
        }
        return ans;
    }
};