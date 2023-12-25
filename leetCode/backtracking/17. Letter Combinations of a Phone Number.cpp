class Solution {
public:
    void util(int index, int n, string digits,map<int, string> values, string &temp, vector<string>&ans) {
        if(temp.size()==n) {
            ans.push_back(temp);
            return;
        }
        int i=digits[index]-'0';
        int j=values[i].size();
        for(int k=0; k<j; k++) {
            temp.push_back(values[i][k]);
            util(index+1, n, digits, values, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty()) 
            return ans;
        map<int, string> values;
         values = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

        int index=0;
        int n=digits.size();
        string temp="";
        util(index, n, digits, values, temp, ans);
        return ans;

    }
};