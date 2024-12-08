class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n=strength.size();
        int bitmask = 0;
        int dp[n+1][(1<<n)];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<(1<<n);j++)
            {
                dp[i][j]=INT_MAX;
            }
        }

        dp[0][0]=0;
        int X=1;
        for(int i=1;i<=n;i++)
        {
            vector<int> vec;
            for(int j=0;j<(1<<n);j++)
            {
                if(dp[i-1][j]!=INT_MAX)vec.push_back(j);
            }
            for(int bitmask:vec)
            {
                for(int j=0;j<n;j++)
                {
                    if(!(bitmask&(1<<j)))
                    {
                        dp[i][bitmask|(1<<j)]=min(dp[i][bitmask|(1<<j)],int(ceil((double)strength[j]/(X+(i-1)*K))) + dp[i-1][bitmask]);
                    }
                }
            }
        }
        return dp[n][(1<<n)-1];
    }
};