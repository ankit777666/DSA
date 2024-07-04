int KthMissingElement(int a[], int n, int k)
{
    // Complete the function
    int low=0, high=n-1;
    
    while(low<=high) {
        int mid=low+(high-low)/2;
        int diff=a[mid]-(mid+a[0]);
        if(diff<k)
            low=mid+1;
        else
            high=mid-1;
            
    }
    if(low==n)
        return -1;
    return k+low+a[0]-1;
}