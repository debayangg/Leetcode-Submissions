class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=0;
        for(int i:nums)
        {
            mx=max(mx,i);
        }
        int i=0,j=0,n=nums.size();
        long long cnt=0,ans=0;
        if(nums[j]==mx)cnt++;
        
        for(;i<n && j<n;)
        {
            if(cnt>=k)
            {
                ans+=n-j;
                if(nums[i]==mx)cnt--;
                i++;

            }
            else
            {
                j++;
                if(j!=n && nums[j]==mx)cnt++;
            }
        }
        return ans;
    }
};