class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
    
        // Your code here
        vector<int>v(maxx+1,0);
        for(int i=0; i<n; i++) 
            for(int j=L[i]; j<=R[i]; j++) 
                v[j]++;
        int max=1,ans=0;
        for(int i=0;i<=maxx;i++){
           if(v[i]>max){
               max=v[i];
               ans=i;
            }
        }
        return ans;
        
    }
};