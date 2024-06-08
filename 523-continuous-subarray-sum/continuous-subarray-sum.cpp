class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> num;
        map<long long,set<int>> m;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum%k==0 && i>0)return true;
            m[sum%k].insert(i);
        }
        sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int val=sum%k;
            auto it = lower_bound(m[val].begin(),m[val].end(),i);
            if(it!=m[val].begin() && i-*(m[val].begin())>1)
            return true;
        }
        return false;
    }
};