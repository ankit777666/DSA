class Solution
{
public:
void subsetSumsUtil(vector<int>arr, int N ,vector<int>&ans, int index, int sum) {
    if(index==N) {
        ans.push_back(sum);
        return;
    }
    subsetSumsUtil(arr, N, ans, index+1, sum+arr[index]);
    subsetSumsUtil(arr, N, ans, index+1, sum);
    
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int index = 0; int sum=0;
        subsetSumsUtil(arr, N, ans, index, sum);
        return ans;
    }
};