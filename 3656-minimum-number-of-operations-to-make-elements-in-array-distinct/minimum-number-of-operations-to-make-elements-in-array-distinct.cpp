class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool flag=true;
        int n=nums.size(), id=-1;
        map<int,int> mp;
        for(int i=n-1;i>=0;i--)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            {
                id=i;
                break;
            }
        }
        if(id==-1)return 0;
        return (id/3)+1;

    }
};