class Solution {
    public int specialTriplets(int[] nums) {
        HashMap<Integer,Long> mp1 = new HashMap<>();
        HashMap<Integer,Long> mp2 = new HashMap<>();

        int n =  nums.length;

        for(int i=n-1;i>=1;i--)
        {
            mp2.merge(nums[i],1L,Long::sum);
        }
        mp1.put(nums[0],1L);

        long cnt=0;
        //System.out.println(mp2.get(0));
        for(int j=1;j<n;j++)
        {
            mp2.put(nums[j],mp2.get(nums[j])-1L);
            cnt+=mp1.getOrDefault( 2*nums[j], 0L) * mp2.getOrDefault( 2*nums[j], 0L);
            mp1.put(nums[j], mp1.getOrDefault( nums[j], 0L) + 1L);
        }
        cnt=cnt%((long)1e9+7);
        return (int)cnt;
    }
}