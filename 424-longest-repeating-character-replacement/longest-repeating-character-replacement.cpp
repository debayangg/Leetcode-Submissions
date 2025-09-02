class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int i=0,j=0,mx=0;
        int mx1=0;
        char mxi;
        while(j<s.size())
        {
            int a = mp[s[j]];
            char c = s[j];
            mp[s[j]]++;

            if(mp[s[j]]>mx1)
            {
                mx1=mp[s[j]];
                mxi=s[j];
            }
            
            if(j-i+1-mx1>k)
            {
                mp[s[i]]--;
                if(s[i]==mxi)mx1=mp[s[i]];
                i++;
            }
            else
            {
                mx=max(mx,j-i+1);
            }
            j++;
        }
        return mx;
    }
};