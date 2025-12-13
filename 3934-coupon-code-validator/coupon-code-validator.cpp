class Solution {
public:
    bool valid(string s)
    {
        if(s.size()==0)return false;
        map<char,int> mp;
        for(char c='a';c<='z';c++)mp[c]=1;
        for(char c='A';c<='Z';c++)mp[c]=1;
        for(char c='0';c<='9';c++)mp[c]=1;
        mp['_']=1;

        for(int i=0;i<s.size();i++)
        {
            if(!mp[s[i]])return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        map<string,vector<string>> ans;
        map<string,int> mp;
        mp["electronics"]=1;
        mp["grocery"]=1;
        mp["pharmacy"]=1;
        mp["restaurant"]=1;
        for(int i=0;i<n;i++)
        {
            if(!valid(code[i]))continue;

            if(!mp[businessLine[i]])continue;
            if(!isActive[i])continue;
            
            ans[businessLine[i]].push_back(code[i]);
        }
        vector<string> res;
        for(auto id:mp)
        {
            string key = id.first;
            sort(ans[key].begin(),ans[key].end());
            for(string x:ans[key])
            res.push_back(x);
        }
        return res;
    }
};