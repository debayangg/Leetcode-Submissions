class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0),stk;
        int count=0;
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {
                count++;
                stk.push_back(i);
            }
            while(stk.size())
            {
                int v = stk[stk.size()-1];
                stk.pop_back();
                if(!visited[v]){
                    visited[v]++;
                    for(int j=0;j<n;j++)
                    {
                        if(isConnected[v][j])
                        stk.push_back(j);
                    }
                }
            }
        }
        return count;
    }
};