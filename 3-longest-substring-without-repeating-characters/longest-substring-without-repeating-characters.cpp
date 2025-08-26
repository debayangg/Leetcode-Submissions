class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.size();
        if(n==1)return 1;
        map<char,int> mp;
        int mx=0;
        while(j<n)
        {
            if(mp[s[j]]!=0)
            {
                i=max(i,mp[s[j]]);
                mp[s[j]]=j+1;
                mx=max(mx,j-i+1);
            }
            else
            {
                mp[s[j]]=j+1;
                mx=max(mx,j-i+1);
            }
            j++;
        }
        return mx;
    }
};