class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int a,b;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.contains(target-nums[i]))
            {
                a=mp[target-nums[i]]-1;
                b=i;
                break;
            }
            mp[nums[i]]=i+1;
        }
        return vector<int>({a,b});
    }
};