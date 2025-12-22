class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), wn = strs[0].size();
        vector<int> check(n,0);
        int cnt=0;
        for(int i=0;i<wn;i++)
        {
            bool flag=false;
            int val = -1;
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]<strs[j-1][i] && !check[j])
                {
                    cnt++;
                    flag=true;
                    break;
                }
            }
            if(flag)  continue;
            
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]>strs[j-1][i])
                {
                    check[j]=1;
                }
            }
        }
        return cnt;
    }
};