class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> wd;
        for(int i=0;i<s.size();)
        {
            string w="";
            for(int j=0;j<k && i<s.size();j++,i++)
            {
                 w+=s[i];
            }
            wd.push_back(w);
        }
        while(wd[wd.size()-1].size()!=k)
        {
            wd[wd.size()-1]+=fill;
        }
        return wd;
    }
};