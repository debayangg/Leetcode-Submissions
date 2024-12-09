class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i]%2)==(nums[i+1]%2))
            ans.push_back(i);
        }
        for(int i:ans)
        {
            cout<<i;
        }
        cout<<endl;
        vector<bool> special;
        for(vector<int> a:queries)
        {
            int st=a[0],en=a[1];
            auto id = lower_bound(ans.begin(),ans.end(),st);
            if(id!=ans.end() && *id<en)
            {
                special.push_back(false);
            }
            else
            {
                special.push_back(true);
            }
        }
        return special;
    }
};