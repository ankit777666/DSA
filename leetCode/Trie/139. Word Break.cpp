class trieNode {
  public:
    trieNode* children[26];
    bool isEndOfWord;
};
class trie {
  public:
    
    trieNode* root;
    trie() {
      root=new trieNode();
      for(int i=0; i<26; i++)
        root->children[i]=NULL;
      root->isEndOfWord=false;
    }
    void insert(string str) {
      trieNode* pCrawl=root;
      for(auto ch : str) {
        if(pCrawl->children[ch-'a']==NULL)
          pCrawl->children[ch-'a'] = new trieNode();
        pCrawl=pCrawl->children[ch-'a'];
      }
      pCrawl->isEndOfWord=true;
    }
};
class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
      trie newTrie;
      for(auto word : wordDict) {
        newTrie.insert(word);
      }
      vector<int>dp(s.size(),-1);
      for(int i=0; i<s.size(); i++) {
        if(i-1==-1 || dp[i-1]==1) {
          trieNode* current=newTrie.root;
          for(int j=i; j<s.size(); j++) {
            if(current->children[s[j]-'a']==NULL)
              break;
            current=current->children[s[j]-'a'];
            if(current->isEndOfWord) {
              dp[j]=1;
            }
          }
        }
      }
      if(dp[s.size()-1]==1)
        return true;
      return false;

    }
};