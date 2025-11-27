class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        map<int,long long> mp;
        for(int i=0;i<k;i++)
        {
            mp[i]=LLONG_MAX;
        }
        long long mx=LLONG_MIN;
        vector<long long> pf(nums.size(),0LL);
        pf[0]=nums[0];
        mp[0]=pf[0];
        if(k==1)mx=pf[0];
        for(int i=1;i<nums.size();i++)
        {
            pf[i]=nums[i]+pf[i-1];
            int rem = i%k;
            //cout<<pf[i]<<" "<<rem<<" "<<mp[rem]<<"\n";
            if(mp[rem]!=LLONG_MAX && mx<pf[i]-mp[rem] || (mp[rem]<0 && pf[i]<0))
            {
                mx=max(mx,pf[i]-mp[rem]);
            }
            if((i+1)%k==0)
            {
                mx=max(mx,pf[i]);
            }
            mp[rem]=min(mp[rem],pf[i]);
        }
        return mx;
    }
};