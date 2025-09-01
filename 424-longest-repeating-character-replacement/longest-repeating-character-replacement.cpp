class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        set<pair<int,char>> st;
        int i=0,j=0,mx=0;
        while(j<s.size())
        {
            int a = mp[s[j]];
            char c = s[j];
            mp[s[j]]++;
            
            if(a) st.erase({a,c});
            st.insert({mp[s[j]],c});

            int mx1=(*st.rbegin()).first;
            
            if(j-i+1-mx1>k)
            {
                st.erase({mp[s[i]],s[i]});
                mp[s[i]]--;
                if(mp[s[i]]) st.insert({mp[s[i]], s[i]});
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