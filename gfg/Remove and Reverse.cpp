class Solution {
  public:
    string removeReverse(string S) {
        // code here
        int i=0, j=S.size()-1;
        unordered_map<char, int> umap;
        bool flag=true;
        int count=0;
        
        for(auto s : S) 
            umap[s]++;
        string start="", end="";
        while(i<=j) {
            char ch;
            if(flag) {
                ch=S[i++];
            }
            else {
                ch=S[j--];
            }
            if(umap[ch]>1) {
                umap[ch]--;
                count++;
                flag=!flag;
            }
            else {
                if(flag)
                    start+=ch;
                else
                    end=ch+end;
            }
            
        }
        string ans=start+end;
        if(count%2==1)
            reverse(ans.begin(), ans.end());
        return ans;
    }
};