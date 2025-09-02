class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[28];
        int i=0,j=0,mx=0;
        int mx1=0;
        while(j<s.size())
        {
            int a = mp[s[j]-'A'];
            char c = s[j];
            mp[s[j]-'A']++;

            mx1=max(mx1,mp[s[j]-'A']);
            
            if(j-i+1-mx1>k)
            {
                mp[s[i]-'A']--;
                i++;
            }
                mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};