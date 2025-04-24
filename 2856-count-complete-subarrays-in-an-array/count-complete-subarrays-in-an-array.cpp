class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        int n=nums.size(), cnt=0, dis=0, dis1=0;
        set<int> s;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        dis=s.size();
        bool flag=true;
        for(int i=0,j=0;i<n && j<n;)
        {
            if(mp[nums[j]]==0 && flag)cnt++;
            if(flag)
            mp[nums[j]]++;
            else
            flag=true;

            if(cnt==dis)
            {
                cout<<i<<" "<<j<<endl;
                for(auto id:mp)
                {
                    cout<<id.first<<" "<<id.second<<endl;
                }
                dis1+=n-j;
                if(mp[nums[i]]==1)cnt--;
                mp[nums[i]]--;
                i++;
                if(i>j)j=i;
                else flag=false;
            }
            else
            {
                j++;
            }
        }
        return dis1;
    }
};