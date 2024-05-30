class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int arr[n];
        arr[0]=nums[0];
        if(n>1)
        arr[1]=max(nums[0],nums[1]);
        if(n>2)
        arr[2]=max(nums[2]+nums[0],nums[1]);
        for(int i=3;i<n;i++)
        {
            arr[i]=max(arr[i-1],max(nums[i]+arr[i-2],nums[i]+arr[i-3]));
        }
        return arr[n-1];
    }
};