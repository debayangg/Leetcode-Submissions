class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        int dp[n][m];
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else if(i==0 && j==0)
                {
                    dp[i][j]=1;
                }
                else{
                    int up=0,left=0;
                    up=(i>0)?dp[i-1][j]:0;
                    left=(j>0)?dp[i][j-1]:0;
                    dp[i][j]=up+left;
                }
            }
        }

        return dp[n-1][m-1];
    }
};