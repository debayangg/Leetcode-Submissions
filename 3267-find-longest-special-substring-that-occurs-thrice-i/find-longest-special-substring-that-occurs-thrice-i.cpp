class Solution {
public:
    int maximumLength(string s) 
    {
        int n=s.size();
        map<char,map<int,int>> mp;
        vector<int> ans;
        int cnt=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
            }
            else
            {
                mp[s[i-1]][cnt]++;
                cnt=1;
            }
        }
        if(cnt>0)
        mp[s[n-1]][cnt]++;

        for(auto id:mp)
        {
            char ch=id.first;
            map<int,int> mp1=id.second;
            int last = mp1.rbegin()->first;

            for(int x=last;x>=1;x--)
            {
                int occurence = mp1[x];
                for(int i=x-1;i>=1;i--)
                {
                    mp1[i]+=(x-i+1)*occurence;
                }
                if(occurence>2)
                {
                    ans.push_back(x);
                    break;
                }
            }
        }
        sort(ans.rbegin(),ans.rend());
        return (ans.size())?ans[0]:-1;
    }
};