class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0,n=s.size(),m=t.size();
        for(;i<n && j<m;i++)
        {
            if(s[i]==t[j])
            j++;
        }
        return (m-j);
    }
};