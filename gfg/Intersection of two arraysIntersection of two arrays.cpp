class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        if(m<n) return NumberofElementsInIntersection(b, a, m, n);
        int ans=0;
        unordered_map<int ,int> umap;
        for(int i=0; i<n; i++)
            umap[a[i]]++;
        for(int i=0; i<m; i++) {
            if(umap.find(b[i])!=umap.end()) {
                ans++;
                umap.erase(b[i]);
            }
        }
        return ans;
    }
};