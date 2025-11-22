class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int i=-1,j=0;
        List<Integer> numsl = Arrays.stream(nums).boxed().collect(Collectors.toList());
        for(;j<numsl.size();j++)
        {
            if(numsl.get(j)%2==0)
            {
                Collections.swap(numsl,++i,j);
            }
        }
        return numsl.stream().mapToInt(Integer::intValue).toArray();
    }
}