class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>diff(nums.size(),0);
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            diff[a]+=1;
            if(b+1<nums.size())
            {
                diff[b+1]-=1;
            }
        }
        int  curr=0;
        for(int i=0;i<nums.size();i++)
        {
            curr+=diff[i];
            nums[i]-=curr;
            if(nums[i]>0)
            {
                return false;
            }
        }
        return true;
    }
};