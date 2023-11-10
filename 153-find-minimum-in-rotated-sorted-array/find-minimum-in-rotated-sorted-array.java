class Solution {
    public int findMin(int[] nums) {
        int i=0,j=nums.length-1,min=5001;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]>=nums[i])
            {
                min=(min>nums[i])?nums[i]:min;
                i=mid+1;
            }
            else
            {
                min=(min>nums[mid])?nums[mid]:min;
                j=mid-1;
            }
        }

        return min;
    }
}