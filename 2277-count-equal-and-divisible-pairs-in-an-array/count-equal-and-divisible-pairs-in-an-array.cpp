class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
        int n=nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        int cnt=0;
        for(auto id:mp)    
            for(int i=0;i<id.second.size();i++)
            {
                for(int j=i+1;j<id.second.size();j++)
                {
                    if(id.second[i]*id.second[j]%k==0)cnt++;
                }
            }
        
        return cnt;
    }
};