class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> factorial, inv_factorial;

    int power(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1LL * res * a % MOD;
            a = 1LL * a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precomputeFactorials(int n) {
        factorial.resize(n + 1);
        inv_factorial.resize(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i)
            factorial[i] = 1LL * factorial[i - 1] * i % MOD;
        inv_factorial[n] = power(factorial[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            inv_factorial[i] = 1LL * inv_factorial[i + 1] * (i + 1) % MOD;
    }

    int nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return 1LL * factorial[n] * inv_factorial[r] % MOD * inv_factorial[n - r] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        precomputeFactorials(n + 14); // up to 14-length chains

        // dp[i][len] = number of sequences of length len ending at value i
        vector<vector<int>> dp(maxValue + 1, vector<int>(15, 0));
        for (int i = 1; i <= maxValue; ++i)
            dp[i][1] = 1;

        for (int len = 2; len <= 14; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int k = 2 * i; k <= maxValue; k += i) {
                    dp[k][len] = (dp[k][len] + dp[i][len - 1]) % MOD;
                }
            }
        }

        int result = 0;
        for (int val = 1; val <= maxValue; ++val) {
            for (int len = 1; len <= 14; ++len) {
                if (dp[val][len]) {
                    result = (result + 1LL * dp[val][len] * nCr(n - 1, len - 1) % MOD) % MOD;
                }
            }
        }

        return result;
    }
};
