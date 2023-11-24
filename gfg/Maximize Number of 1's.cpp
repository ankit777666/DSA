class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int ans = 0;
        int i=0,j=0;
        
        while(j<n) {
            if(arr[j] ==0)
                m--;
            if(m<0) {
                if(arr[i]==0)
                    m++;
                i++;
            }
            
            
            j++;
            
        }
        return j-i;
    }  
};