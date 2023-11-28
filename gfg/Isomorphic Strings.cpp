class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n1 = str1.size();
        int n2 = str2.size();
        if(n1 != n2) return false;
        
        unordered_map<char, char> umap1;
        unordered_map<char, bool> umap2;
        
        for(int i=0; i<n1; i++) {
            char ch1 = str1[i];
            char ch2 = str2[i];
            
            if(umap1.find(ch1) != umap1.end()) {
                if(umap1[ch1] != ch2)
                    return false;
                
            }
            else {
                if(umap2.find(ch2) != umap2.end())
                    return false;
                
                umap1[ch1] = ch2;
                umap2[ch2] = true;
                
            }
        }
        return true;
        
        
        
    }
};