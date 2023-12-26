class Solution {
public:
    bool isPalindrome(string s, int low, int high) {
        while(low<high) {
            if(s[low++]!=s[high--])
                return false;
        }
        return true;
    } 
    void partitionUtil(int index,string s, vector<string>&v, vector<vector<string>>&ans) {
        if(index==s.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=index; i<s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                v.push_back(s.substr(index, i-index+1));
                partitionUtil(i+1, s, v, ans);
                v.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        int index=0;
        partitionUtil(index, s, v, ans);
        return ans;
    }
};