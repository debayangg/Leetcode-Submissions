class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp =  new HashMap<>();
        int a=0,b=0;
        for(int i=0;i<nums.length;i++)
        {
            if(mp.containsKey(target-nums[i]))
            {
                a=mp.get(target-nums[i])-1;
                b=i;
                break;
            }
            mp.put(nums[i],i+1);
        }
        return new int[]{a,b};
    }
}