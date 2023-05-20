class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max=0,current=0,n=nums.length;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                current++;
            }
            if(nums[i]==0)
            {
                if(current>max)
                max=current;

                current=0;
            }
            if(i==n-1)
            {
                if(current>max)
                max=current;

                current=0;
            }
        }

        return max;
    }
}