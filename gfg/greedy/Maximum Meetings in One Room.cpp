class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<int>ans;
        vector<pair<pair<int,int>,int>>ds;
        for(int i=0; i<N; i++) {
            // ds[i]->first->first=S[i]
            ds.push_back({{F[i],S[i]},i+1});
        }
        int last=INT_MIN;
        sort(ds.begin(),ds.end());
        for(int i=0; i<N; i++) {
            if(ds[i].first.second>last) {
                last=ds[i].first.first;
                ans.push_back(ds[i].second);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};