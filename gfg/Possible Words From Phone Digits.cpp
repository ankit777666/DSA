class Solution
{
    public:
    void possibleWordsUtil(int a[], int N, vector<string>&ans, vector<string>&words, int i, string temp) {
        
        if(i==N) {
           ans.push_back(temp);
            return; 
        }
        int num = a[i]; string val = words[num];
        for(int index = 0; index<val.size(); index++) {
            temp.push_back(val[index]);
            possibleWordsUtil(a, N, ans, words, i+1, temp);
            temp.pop_back();
        }
            
        
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> words = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string temp = "";
        possibleWordsUtil(a,N, ans, words, 0, temp);
        return ans;
    }
};