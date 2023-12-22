class Solution {
  public:
    bool isPalindrome(string S, int start, int end) {
        while(start<=end) {
            if(S[start++]!=S[end--])
                return false;
        }
        return true;
    }
    void util(int index, string S, vector<string>&path, vector<vector<string>>&ans) {
        if(index==S.size()) {
            ans.push_back(path);
            return;
        }
        for(int i=index; i<S.size(); i++) {
            if(isPalindrome(S, index, i)) {
                path.push_back(S.substr(index, i-index+1));
                util(i+1, S, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>>ans;
        vector<string> path;
        int index=0;
        util(0, S, path, ans);
        return ans;
    }
};