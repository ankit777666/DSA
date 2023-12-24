class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long temp[], int left, int mid, int right) {
        int i,j,k;
        long long res = 0;
        i=left; j=mid; k=left;
        while((i <= mid-1) && (j<=right)) {
            if(arr[i]<=arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                res += mid - i;
            }
        }
        while(i <=mid-1)
            temp[k++] = arr[i++];
        while(j<=right)
            temp[k++] = arr[j++];
            
        for(i = left; i<=right; i++)
            arr[i] = temp[i];
        return res;
    }
    
    long long mergeSort(long long arr[], long long temp[], int left, int right) {
        int mid; long long res = 0;
        if( right> left) {
            int mid = (right-left) / 2 + left;
            
            res += mergeSort(arr, temp, left, mid);
            res += mergeSort(arr, temp, mid+1, right);
            res += merge(arr, temp, left, mid+1, right);
        }
        return res;
            
        
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        long long res = 0;
        res = mergeSort(arr, temp, 0, N-1);
        return res;
        
    }

};