class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n,false);
        long long num=0;
        for(int i=0;i<n;i++)
        {
            num<<=1;
            num+=nums[i];
            if(num%5==0)ans[i]=true;
            num=num%5;
        }
        return ans;
    }
};