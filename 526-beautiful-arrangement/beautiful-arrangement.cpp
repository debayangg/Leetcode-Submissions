class Solution {
public:
    int countArrangement(int n) 
    {
        int dp[(1<<n)];

        for(int i=0;i<(1<<n);i++)dp[i]=0;
        dp[0]=1;

        for(int i=0;i<(1<<n);i++)
        {
            int cnt=__builtin_popcount(i);
            for(int j=0;j<n;j++)
            {
                if(!(i&(1<<j)))
                {
                    if((j+1)%(cnt+1)==0 || (cnt+1)%(j+1)==0)
                    dp[i|(1<<j)] += dp[i];
                }
            }
        }
        return dp[(1<<n)-1];
    }
};