class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n1=arr1.size(), n2=arr2.size();
        int i=0, j=0;
        int count=0;
        
        while(i<n1 && j<n2) {
            if(arr1[i]<arr2[j]) {
                count++;
                if(count==k)
                    return arr1[i];
                i++;
            }
            else {
                count++;
                if(count==k)
                    return arr2[j];
                j++;
            }
        }
        
        while(i<n1) {
            count++;
            if(count==k)
                return arr1[i];
            i++;
        }
        while(j<n2) {
            count++;
            if(count==k)
                return arr2[j];
            j++;
        }
        return -1;
    }
};