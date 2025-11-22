class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=-1,j=0;
        for(;j<nums.size();j++)
        {
            if(nums[j]%2==0)
            {
                i++;
                int tmp = nums[i];
                nums[i]=nums[j];
                nums[j]=tmp;
            }
        }
        return nums;
    }
};