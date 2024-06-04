class Solution {
public:
    string compressedString(string word) {
        string ans="",wd="";
        for(int i=0;i<word.size();i++)
        {
            if(!wd.size())
            wd+=word[i];
            else
            {
                if(word[i]!=word[i-1] || wd.size()>=9)
                {
                    ans+=to_string(wd.size());
                    ans+=wd[wd.size()-1];
                    wd="";
                    wd+=word[i];
                }
                else
                {
                    wd+=word[i];
                }
            }
        }
        ans+=to_string(wd.size());
        ans+=wd[wd.size()-1];
        return ans;
    }
};