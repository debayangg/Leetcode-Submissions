class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();
        vector<long> dp(1 << n, LONG_MAX); 
        dp[0] = 0; 

        for (int i = 0; i < (1 << n); ++i) { 
            int f = 1 + __builtin_popcount(i) * K;
            for (int j = 0; j < n; ++j) {
                if (!(i & (1 << j))) { 
                    long time = (strength[j] + f - 1) / f; 
                    dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + time); 
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
};