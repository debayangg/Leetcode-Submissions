class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int dp[(1<<n)];
        for(int i=0;i<(1<<n);i++)
        dp[i]=INT_MAX;
        dp[0]=0;
        for(int i=0;i<(1<<n);i++)
        {
            int cnt=__builtin_popcount(i);
            for(int j=0;j<n;j++)
            {
                if(!(i&(1<<j)))
                {
                    dp[i|(1<<j)]=min(dp[i|(1<<j)] , (nums1[cnt]^nums2[j])+dp[i]);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};