class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        map<int, multiset<int> > mp;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]%3].insert(nums[i]);
            sum+=nums[i];
        }
        if(sum%3==0)return sum;
        else if(sum%3==1)
        {
            int sum1=0,sum2=0;
            if(mp[1].size())
            sum1 = sum-*(mp[1].begin());
            if(mp[2].size()>1)
            sum2 = sum - *(mp[2].begin()) - *next(mp[2].begin(),1);
            return max(sum1,sum2);
        }
        else if(sum%3==2)
        {
            int sum1=0,sum2=0;
            if(mp[2].size())
            sum1 = sum-*(mp[2].begin());
            if(mp[1].size()>1)
            sum2 = sum - *(mp[1].begin()) - *next(mp[1].begin(),1);
            return max(sum1,sum2);
        }
        return 0;
    }
};