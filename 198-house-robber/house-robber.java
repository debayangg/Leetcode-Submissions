class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        int v1=0,v2=0,v3=0,curr=0;
        v1=nums[0];
        curr=v1;
        if(n>1)
        {
            v2=Math.max(nums[0],nums[1]);
            curr=v2;
        }
        if(n>2)
        {
            v3=Math.max(nums[2]+nums[0],nums[1]);
            curr=v3;
        }
        for(int i=3;i<n;i++)
        {
            curr=Math.max(v3,Math.max(nums[i]+v2,nums[i]+v1));
            v1=v2;
            v2=v3;
            v3=curr;
        }
        return curr;
    }
}