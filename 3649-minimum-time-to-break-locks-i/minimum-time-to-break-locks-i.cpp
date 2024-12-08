class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();
        vector<long> dp(1 << n, LONG_MAX); // Initialize DP table
        dp[0] = 0; // Base case: No workers, no time

        for (int i = 0; i < (1 << n); ++i) { // Iterate over all subsets
            int f = 1 + __builtin_popcount(i) * K; // Efficiency factor for current subset
            for (int j = 0; j < n; ++j) { // Try adding a new worker to the subset
                if (!(i & (1 << j))) { // Worker j not in subset
                    long time = (strength[j] + f - 1) / f; // Calculate time for worker j
                    dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + time); // Update DP state
                }
            }
        }
        
        return dp[(1 << n) - 1] < LONG_MAX ? dp[(1 << n) - 1] : -1; // Final result
    }
};