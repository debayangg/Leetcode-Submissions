class Solution {
public:
    int countLargestGroup(int n) 
    {
        map<int,int> mp;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            int cp=i,sum=0;
            while(cp!=0)
            {
                sum+=cp%10;
                cp/=10;
            }
            mp[sum]++;
            mx=max(mx,mp[sum]);
        }
        int cnt=0;
        for(auto id:mp)
        {
            if(id.second==mx)cnt++;
        }
        return cnt;
    }
};