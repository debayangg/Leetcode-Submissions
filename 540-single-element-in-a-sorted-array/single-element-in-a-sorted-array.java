class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n=nums.length;
        if(n==1)
        return nums[0];
        int i=0,j=n-1,num=-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(mid!=n-1 && nums[mid]==nums[mid+1])
            {
                if((j-mid)%2==0)
                i=mid+2;
                else
                j=mid-1;
            }
            else if(mid!=0 && nums[mid]==nums[mid-1])
            {
                if((mid-i)%2==0)
                j=mid-2;
                else
                i=mid+1;
            }
            else
            {
                return nums[mid];
            }
        }
        System.out.println(i+" "+j);
        if(i>=n)
        return nums[j];
        else if(j<=-1)
        return nums[i];
        else if(i-j==2)
        return nums[j+1];
        else
        {
            if(nums[i+1]==nums[i])
            return nums[j];
            else
            return nums[i];
        }
    }
}