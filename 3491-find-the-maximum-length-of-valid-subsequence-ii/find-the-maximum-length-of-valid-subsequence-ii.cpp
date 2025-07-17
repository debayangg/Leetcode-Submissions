class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]%=k;
            mp[nums[i]]++;
            ans=max(ans,mp[nums[i]]);
            //cout<<nums[i]<<" ";
        }
        //cout<<endl;

        vector<vector<int>> dp(k, vector<int>(k,0));

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<k;j++)
            {
                dp[j][nums[i]]=dp[nums[i]][j]+1;
                ans=max(ans,dp[j][nums[i]]);
            }
        }

        return ans;
    }
};