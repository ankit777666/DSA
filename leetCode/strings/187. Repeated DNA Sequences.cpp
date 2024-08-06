class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      unordered_map<string,int> umap;
      int n=s.size();
      vector<string>ans;
      if(n<10) return ans;

      for(int i=0; i<n-9; i++) {
        string str=s.substr(i,10);
        umap[str]++;
      }
      for(auto ele : umap) {
        if(ele.second>1)
          ans.push_back(ele.first);
      }
      return ans;
        
    }
};