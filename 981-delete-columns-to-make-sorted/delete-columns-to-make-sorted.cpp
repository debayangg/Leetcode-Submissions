class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {
                    s.insert(i);
                    break;
                }
            }
        }

        return s.size();
    }
};