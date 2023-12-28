class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int n1=players.size(), n2=trainers.size();
        int ans=0;
        int i=0, j=0;
        while(i<n1 && j<n2) {
            if(players[i]<=trainers[j]) {
                ans++;
                i++;j++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};