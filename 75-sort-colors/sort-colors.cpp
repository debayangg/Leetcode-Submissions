class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c1=0,c2=0,c3=0;
        for(int i:nums)
        {
            if(i==0)c1++;
            if(i==1)c2++;
            if(i==2)c3++;
        }
        int i=0;
        for(;i<c1;i++)
        nums[i]=0;
        for(;i<c1+c2;i++)
        nums[i]=1;
        for(;i<c1+c2+c3;i++)
        nums[i]=2;
    }
};