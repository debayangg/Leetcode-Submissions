class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            a+=(nums[i]==0)*1;
            b+=(nums[i]==1)*1;
            c+=(nums[i]==2)*1;
        }   
        for(int i=0;i<nums.size();i++)
        {
            if(a>0)
            {
                nums[i]=0;
                a--;
            }
            else if(b>0)
            {
                nums[i]=1;
                b--;
            }
            else
            {
                nums[i]=2;
            }
        }
    }
};