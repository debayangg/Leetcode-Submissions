class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n=strength.size();
        int lim=(1<<n);
        vector<vector<long long>>dp(lim,vector<long long>(100,INT_MAX));
        dp[0][1]=0;
        for(int i=0;i<lim;++i)
        {
            for(int j=1;j<100;++j)
            {
                if(dp[i][j]==INT_MAX)
                    continue;
                for(int k=0;k<n;++k)
                {
                    if(!(i&(1<<k)))
                    {
                        long long temp=(strength[k]+j-1)/j;
                        int ni=i|(1<<k),nk=j+K;
                        dp[ni][nk]=min(dp[ni][nk],dp[i][j]+temp);
                    }
                }
            }
        }
        long long ans=INT_MAX;
        for(int i=1;i<100;++i)
            ans=min(ans,dp[lim-1][i]);
        return (ans<=INT_MAX)?(int)ans:-1;
    }
};