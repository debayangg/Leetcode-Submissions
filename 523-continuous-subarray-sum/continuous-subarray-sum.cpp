class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> num;
        map<long long,int> m;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum%k==0 && i>0)return true;
            if(!m[sum%k])
            m[sum%k]=i+1;
        }
        sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int val=sum%k;
            if(i-m[val]>0)
            return true;
        }
        return false;
    }
};