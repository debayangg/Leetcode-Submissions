class Solution {
public:
    int minimumLength(string s) 
    {
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        int cnt=0;
        for(auto i:mp)
        {
            if(i.second%2)
            cnt++;
            else
            cnt+=2;
        }
        return cnt;
    }
};