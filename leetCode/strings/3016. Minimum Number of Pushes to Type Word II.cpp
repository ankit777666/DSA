class Solution {
public:
    
    int minimumPushes(string word) {
      int n=word.size();
      int count=0;
      vector<int>v(26,0);
      for(auto ch:word) {
        v[ch-'a']++;
      }
      sort(v.begin(),v.end(),greater<>());
      int ans=0, push=1;
      int keyCount=0;
      for(auto ch : v) {
        ans+=ch*push;
        keyCount++;

        if(keyCount %8 ==0)
          push++;
      }
      return ans;
    }
};