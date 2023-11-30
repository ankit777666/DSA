class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int> ans;
        unordered_map<int, int> umap;
        for(int i=0;i<n;i++) {
            umap[-arr[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto it: umap) {
            pq.push({it.second, it.first});
        }
        while(!pq.empty()) {
            int value = pq.top().first;
            int key = pq.top().second;
            while(value>0) {
                ans.push_back(-key);
                value--;
            }
            pq.pop();
        }
        return ans;
    }
};