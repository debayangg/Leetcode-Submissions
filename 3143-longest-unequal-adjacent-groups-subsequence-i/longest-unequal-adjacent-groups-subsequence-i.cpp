class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> v1,v2;
        int n=words.size();
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(groups[i]!=prev)
            {
                v1.push_back(words[i]);
                prev=groups[i];
            }
        }
        prev=1;
        for(int i=0;i<n;i++)
        {
            if(groups[i]!=prev)
            {
                v2.push_back(words[i]);
                prev=groups[i];
            }
        }
        if(v1.size()>v2.size())
        return v1;
        else
        return v2;
        
    }
};