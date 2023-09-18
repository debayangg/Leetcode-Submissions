import java.util.*;

class Solution {
    public int minimumDifference(int[] nums, int k) {
        Integer array[] = new Integer[nums.length];

        for(int i=0;i<nums.length;i++)
        {
            array[i]=nums[i];
        }

        if(k==1)
        return 0;

        // Sort the array in descending order
        Arrays.sort(array,(a,b) -> b-a);

        int min = array[0]-array[k-1];

        for(int i=0;i<nums.length;i++)
        {
            if(i+k-1>=nums.length)
            break;
            if(min>array[i]-array[i+k-1])
            min=array[i]-array[i+k-1];

        }

        return min;
    }
}