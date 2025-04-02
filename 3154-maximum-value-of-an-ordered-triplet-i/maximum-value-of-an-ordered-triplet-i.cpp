class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        vector<int> mxs(nums.size());
        mxs[1]=nums[0];
        for(int i=2;i<nums.size();i++)
        {
            int mx1=max(mxs[i-1],nums[i-1]);
            mxs[i]=mx1;
        }
        for(int i=1;i<nums.size();i++)
        {
            mxs[i]=mxs[i]-nums[i];
        }
        for(int i=1;i<nums.size();i++)
        {
            mxs[i]=max(mxs[i],mxs[i-1]);
        }
        long long mx=0;
        for(int i=2;i<nums.size();i++)
        {
            mx=max(mx,(long long)nums[i]*mxs[i-1]);
        }
        return mx;
    }
};