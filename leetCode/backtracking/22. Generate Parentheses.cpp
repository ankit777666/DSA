class Solution {
public:
    void util(int countOpen,int countClose,int index, int n, string &temp, vector<string>&ans) {
        if(index==n*2) {
            ans.push_back(temp);
            return;
        }
        if(countOpen<n && index<n*2-1) {
            temp.push_back('(');
            util(countOpen+1, countClose, index+1, n, temp, ans);
            temp.pop_back();
        }
        if(countClose<countOpen && index>0) {
            temp.push_back(')');
            util(countOpen, countClose+1, index+1, n, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int index=0;
        string temp="";
        int countOpen=0, countClose=0;
        util(countOpen,countClose,index, n, temp, ans);
        return ans;
    }
};