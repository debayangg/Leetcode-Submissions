class Solution {
    public boolean search(int[] nums, int target) {
        int n=nums.length,i=0,j=n-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
            {
                return true;
            }

            if(nums[i]==nums[mid] && nums[j]==nums[mid])
            {
                i++;
                j--;
                continue;
            }
            
            if(nums[mid]<=nums[j])
            {
                if(nums[mid]<=target && target<=nums[j])
                i=mid+1;
                else
                j=mid-1;
            }
            else
            {
                if(nums[mid]>=target && target>=nums[i])
                j=mid-1;
                else
                i=mid+1;
            }
        }

        return false;
    }
}
