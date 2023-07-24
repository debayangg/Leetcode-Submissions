class Solution {
    public int maxArea(int[] height) {
        int i=0,j=height.length-1,max=0;
        while(i<j)
        {
            int min=(height[i]>height[j])?height[j]:height[i];
            int val=min*(j-i);
            if(val>max)
            max=val;
            if(height[i]>height[j])
            j--;
            else if(height[i]<height[j])
            i++;
            else
            {
                i++;
                j--;
            }
        }
        return max;
    }
}