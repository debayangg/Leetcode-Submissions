class Solution {
    public int findPeakElement(int[] nums) {
        int n=nums.length,i=0,j=n-1;
        if(n==1)
        return 0;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(mid+1==n)
            {
                if(nums[mid-1]<nums[mid])
                return mid;
                else
                j=mid-1;
            }
            else if(mid-1==-1)
            {
                if(nums[mid+1]<nums[mid])
                return mid;
                else
                i=mid+1;
            }
            else
            {
                int prev=nums[mid-1];
                int next=nums[mid+1];
                int curr=nums[mid];
                if(curr>prev && curr>next)
                return mid;
                else if(curr>prev && curr<next)
                i=mid+1;
                else if(curr<prev && curr>next)
                j=mid-1;
                else
                j=mid-1;
            }
        }
        return -1;
    }
}