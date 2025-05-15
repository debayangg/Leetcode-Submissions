class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> v1,v2;
        int n=words.size();
        int prev1=0,prev2=1;
        for(int i=0;i<n;i++)
        {
            if(groups[i]!=prev1)
            {
                v1.push_back(words[i]);
                prev1=groups[i];
            }
            if(groups[i]!=prev2)
            {
                v2.push_back(words[i]);
                prev2=groups[i];
            }
        }
        if(v1.size()>v2.size())
        return v1;
        else
        return v2;
        
    }
};