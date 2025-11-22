class Solution {
    public int minimumOperations(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++)
        {
            sum+=Math.min((nums[i]%3),3-(nums[i]%3));
        }
        return sum;
    }
}