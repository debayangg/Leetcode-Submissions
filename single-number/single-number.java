import java.util.*;
class Solution {
    public int singleNumber(int[] nums) {
        int length=nums.length;
        Arrays.sort(nums);
        if(length==1)
        return nums[0];

        if(nums[0]!=nums[1])
        return nums[0];

        if(nums[length-1]!=nums[length-2])
        return nums[length-1];

        int l=0, h=length-1;

        while(l<=h)
        {
            int mid=(h-l)/2+l;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                l=mid+1;
                else if(nums[mid]==nums[mid-1])
                h=mid-1;
                else
                return nums[mid];
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                l=mid+1;
                else if(nums[mid]==nums[mid+1])
                h=mid-1;
                else
                return nums[mid];
            }

        }

        return -1;
    }
}