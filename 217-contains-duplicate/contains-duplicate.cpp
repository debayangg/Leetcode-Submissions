class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        bool flag = false;
        for(int x:nums)
        {
            mp[x]++;
            if(mp[x]>1)flag=true;
        }
        return flag;
    }
};