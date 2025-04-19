class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int l=lower-nums[i],u=upper-nums[i];
            auto it1=lower_bound(next(nums.begin(),i+1),nums.end(),l);
            auto it2=upper_bound(next(nums.begin(),i+1),nums.end(),u);
            cnt+=distance(it1,it2);
        }
        return cnt;
    }
};