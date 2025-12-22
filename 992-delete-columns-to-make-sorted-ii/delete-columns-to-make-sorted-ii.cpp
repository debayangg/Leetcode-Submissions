class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), wn = strs[0].size();
        vector<int> check(n,0);
        unordered_set<int> s;
        for(int i=0;i<wn;i++)
        {
            bool flag=true;
            vector<int> checks;
            int val = -1;
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]<strs[j-1][i] && !check[j])
                {
                    flag=false;
                    val = i;
                    break;
                }
                else if(strs[j][i]==strs[j-1][i])
                {
                    flag=false;
                }
                else
                {
                    checks.push_back(j);
                }
            }
            if(val==-1)
            {
                for(int x:checks)check[x]=1;
            }
            else
            {
                s.insert(val);
            }
            if(flag)break;
        }
        return s.size();
    }
};