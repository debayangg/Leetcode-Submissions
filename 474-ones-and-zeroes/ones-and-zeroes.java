class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int strs_length = strs.length;
        int dp[][] = new int[m+1][n+1];
        for(int id=0;id<strs_length;id++)
        {
            String str = strs[id];
            int zero=0, one=0;
            for(char x:str.toCharArray())
            {
                if(x=='1')one++;
                else zero++;
            }
            if(one>n || zero>m)continue;
            for(int i=m;i>=zero;i--)
            {
                for(int j=n;j>=one;j--)
                {
                    dp[i][j] = Math.max(dp[i][j], dp[i-zero][j-one] + 1);
                }
            }
        }
        return dp[m][n];
    }
}