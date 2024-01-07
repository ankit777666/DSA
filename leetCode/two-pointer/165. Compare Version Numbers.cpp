class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.length(),m=version2.length();
        vector<int>v1,v2;
        int i=0,j=0;
        while(i<n || j<m)
        {
            int num=0;
            while(i<n && version1[i]!='.')
            {
                num=num*10+(version1[i]-'0');
                i++;
            }
            i++;
            v1.push_back(num);
            num=0;
            while(j<m && version2[j]!='.')
            {
                num=num*10+(version2[j]-'0');
                j++;
            }
            j++;
            v2.push_back(num);
        }
        
        for(i=0;i<v1.size();i++)
        {
            if(v1[i]<v2[i])
                return -1;
            else if(v1[i]>v2[i])
                return 1;
        }
        return 0;
    }
};