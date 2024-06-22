class Solution {
public:
    void flip(vector<int> &nums, int i)
    {
        int n=i;
        for(;i<n+3 && i<nums.size();i++)
        {
            if(nums[i])nums[i]=0;
            else nums[i]=1;
        }
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size(),i,count=0;
        for(i=0;i<n-2;i++)
        {
            if(nums[i]==0)
            {
                flip(nums,i);
                count++;
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)flag=false;
        }
        if(flag)
        return count;
        else
        return -1;
    }
};