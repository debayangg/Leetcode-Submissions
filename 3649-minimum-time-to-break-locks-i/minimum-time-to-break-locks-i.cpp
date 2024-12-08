class Solution {
public:
    int helper(vector<int>& strength, int K, int X, int bitmask, int lim)
    {
        if(bitmask==lim)
        {
            return 0;
        }

        int n=strength.size();

        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(!(bitmask&(1<<i)))
            {
                ans=min(ans,int(ceil(double(strength[i])/X))+helper(strength, K, X+K, bitmask|(1<<i), lim));
            }
        }
        return ans;
    }
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();
        vector<int> way;
        int ans = helper(strength, K, 1, 0, ((1<<n)-1));
        return ans; 
    }
};