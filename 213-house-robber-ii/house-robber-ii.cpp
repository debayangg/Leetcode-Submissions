class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];

        vector<int> n1,n2;
        for(int i=0;i<nums.size()-1;i++)
        {
            n1.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++)
        {
            n2.push_back(nums[i]);
        }
        return max(rob1(n1),rob1(n2));
    }
    int rob1(vector<int>& nums) {
        int n=nums.size();
        int v1=0,v2=0,v3=0,curr=0;
        v1=nums[0];
        curr=v1;
        if(n>1)
        {
            v2=max(nums[0],nums[1]);
            curr=v2;
        }
        if(n>2)
        {
            v3=max(nums[2]+nums[0],nums[1]);
            curr=v3;
        }
        for(int i=3;i<n;i++)
        {
            curr=max(v3,max(nums[i]+v2,nums[i]+v1));
            v1=v2;
            v2=v3;
            v3=curr;
        }
        return curr;
    }
};