class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> m(26, vector<int> (words.size(),0));
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            for(int j=0;j<s.size();j++)
            {
                int ch=s[j]-'a';
                m[ch][i]++;
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++)
        {
            int f=INT_MAX;
            for(int j=0;j<words.size();j++)
            {
                f=min(f,m[i][j]);
            }
            while(f--)
            {
                char ch='a'+i;
                string str="";
                str+=ch;
                ans.push_back(str);
            }
        }
        return ans;
    }
};