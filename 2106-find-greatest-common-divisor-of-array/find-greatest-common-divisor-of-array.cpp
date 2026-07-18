class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX, mx = 0;
        for(int x:nums)
        {
            mn=min(mn,x);
            mx=max(mx,x);
        }
        return gcd(mn,mx);
    }
};