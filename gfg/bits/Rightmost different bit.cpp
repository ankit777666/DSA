class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        for(int i=0; i<32; i++) {
            if(((m>>i)&1) !=((n>>i)&1))
                return i+1;
        }
        return -1;
    }
};