class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[n-1].size();
        int dp[n][m];
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int lim=triangle[i].size();
            for(int j=0;j<lim;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=triangle[i][j];
                }
                else if(j==0)
                {
                    dp[i][j]=triangle[i][j]+dp[i-1][j];
                }
                else if(j==lim-1)
                {
                    dp[i][j]=triangle[i][j]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(triangle[i][j]+dp[i-1][j],triangle[i][j]+dp[i-1][j-1]);
                }
                if(i==n-1)
                ans=min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};