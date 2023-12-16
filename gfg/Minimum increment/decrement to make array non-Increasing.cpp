class Solution{
public:
    int minOperations(int *a,int n)
    {
        int ans=0;
        priority_queue<int> pq;
        for(int i=n-1; i>=0; i--) {
            if(!pq.empty() && pq.top()>a[i]) {
                ans+=abs(a[i]-pq.top());
                pq.pop();
                pq.push(a[i]);
            }
            pq.push(a[i]);
        }
        return ans;
        
    }
};